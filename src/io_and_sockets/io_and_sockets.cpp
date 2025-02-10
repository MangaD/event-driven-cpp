/**
 * @file io_and_sockets.cpp
 * @brief Demonstrates cross-platform monitoring of both socket events and console I/O.
 *
 * This example creates a simple TCP server that listens on port 12345 for incoming connections
 * and monitors console input for commands. The example is designed to run on both Windows and POSIX
 * systems, using platform-specific mechanisms:
 *
 * - On POSIX systems, the `select()` system call is used to monitor both the server socket and
 *   the standard input (STDIN_FILENO).
 * - On Windows, Winsock’s `select()` function monitors the server socket, while `_kbhit()` is used
 *   in a polling loop to check for console input.
 *
 * Typing "quit" at the console terminates the server loop.
 *
 * @note For Windows, Winsock must be initialized before any socket functions are used, and cleaned
 *       up upon termination.
 */

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>

#ifdef _WIN32
    // Windows-specific definitions and header inclusions.
    // The following headers provide socket programming functions, console input checking,
    // and necessary Windows API functions.
    #define WIN32_LEAN_AND_MEAN
    #include <winsock2.h> // Must be included before windows.h. For Windows socket functions, such as socket(), bind(), etc.
    #include <ws2tcpip.h> // For TCP/IP socket functions, such as inet_pton().
    #include <conio.h>    // For _kbhit() and _getch().
    #include <windows.h>  // For Windows API functions, such as Sleep().
    #pragma comment(lib, "Ws2_32.lib") // Link with the Winsock library.
#else
    // POSIX-specific header inclusions.
    // The following headers provide socket programming and I/O functions on POSIX systems.
    #include <sys/select.h> // For select().
    #include <unistd.h>     // For STDIN_FILENO.
    #include <fcntl.h>      // For fcntl().
#endif

#include "logger.hpp"

namespace io_and_sockets {

/**
 * @brief The port number on which the TCP server listens.
 */
#define PORT 12345

#ifdef _WIN32
/**
 * @brief Initializes Winsock on Windows.
 *
 * This function initializes the Winsock DLL necessary for socket operations on Windows.
 *
 * @return true if initialization is successful, false otherwise.
 */
bool init_winsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Closes a socket on Windows.
 *
 * This function wraps the `closesocket()` call for Windows.
 *
 * @param s The socket to close.
 */
void close_socket(SOCKET s) {
    closesocket(s);
}
#else
/**
 * @brief Closes a socket on POSIX systems.
 *
 * This function wraps the `close()` system call to close a file descriptor.
 *
 * @param s The socket file descriptor to close.
 */
void close_socket(int s) {
    close(s);
}
#endif

int runDemo() {

    common::Logger::setLogLevel(common::LogLevel::Debug);

#ifdef _WIN32
    // Initialize Winsock for Windows socket operations.
    if (!init_winsock()) {
        return 1;
    }
#endif

    // Create a TCP server socket.
#ifdef _WIN32
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket." << std::endl;
        WSACleanup();
        return 1;
    }
#else
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Failed to create server socket." << std::endl;
        return 1;
    }
#endif

    // Set up the server address structure.
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces.

    // Bind the server socket to the specified port.
    if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed." << std::endl;
        close_socket(serverSocket);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    // Start listening on the server socket.
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Listen failed." << std::endl;
        close_socket(serverSocket);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;
    std::cout << "Type 'quit' to exit." << std::endl;

    bool running = true;
    while (running) {
#ifdef _WIN32
        // Create a file descriptor set for Winsock's select() to monitor the server socket.
        fd_set sockfds;
        FD_ZERO(&sockfds);
        FD_SET(serverSocket, &sockfds);

        // Set a timeout for select() of 1 second.
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        common::Logger::debug("Waiting for select() with timeout of 1 second...");
        int sockResult = select(0, &sockfds, NULL, NULL, &tv);
        if (sockResult > 0 && FD_ISSET(serverSocket, &sockfds)) {
            // Accept an incoming connection.
            SOCKET clientSocket = accept(serverSocket, NULL, NULL);
            if (clientSocket != INVALID_SOCKET) {
                std::cout << "Accepted a connection on the server socket." << std::endl;
                close_socket(clientSocket);
            }
        }

    #ifdef TEST_MODE
        // In test mode, simply use std::getline() to read from standard input.
        std::string input;
        if (std::getline(std::cin, input)) {
            std::cout << "Console input: " << input << std::endl;
            if (input == "quit") {
                running = false;
            }
        }
    #else
        // In normal mode, use _kbhit() to check for input without blocking.
        if (_kbhit()) {
            std::string input;
            std::getline(std::cin, input);
            std::cout << "Console input: " << input << std::endl;
            if (input == "quit") {
                running = false;
            }
        }
    #endif
#else
        // On POSIX systems, use select() to monitor both the server socket and standard input.
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);
        FD_SET(STDIN_FILENO, &readfds);

        // Calculate the maximum file descriptor to monitor.
        int maxfd = std::max(serverSocket, STDIN_FILENO);
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        common::Logger::debug("Waiting for select() with timeout of 1 second...");
        int ret = select(maxfd + 1, &readfds, NULL, NULL, &tv);
        if (ret > 0) {
            // Check if the server socket is ready for reading.
            if (FD_ISSET(serverSocket, &readfds)) {
                int clientSocket = accept(serverSocket, NULL, NULL);
                if (clientSocket >= 0) {
                    std::cout << "Accepted a connection on the server socket." << std::endl;
                    close_socket(clientSocket);
                }
            }
            // Check if standard input is ready for reading.
            if (FD_ISSET(STDIN_FILENO, &readfds)) {
                std::string input;
                std::getline(std::cin, input);
                std::cout << "Console input: " << input << std::endl;
                if (input == "quit") {
                    running = false;
                }
            }
        }
#endif
        // Sleep briefly to reduce CPU usage.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Shutting down server." << std::endl;
    close_socket(serverSocket);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}

} // namespace io_and_sockets