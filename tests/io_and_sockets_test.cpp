/**
 * @file io_and_sockets_test.cpp
 * @brief Unit test for the I/O and Sockets demonstration.
 *
 * This test verifies that the I/O and Sockets demonstration (implemented in the
 * io_and_sockets module) terminates automatically when simulated input is provided
 * and correctly accepts a client socket connection.
 *
 * In test mode (with TEST_MODE defined), the demonstration bypasses the Windows-specific
 * _kbhit() polling and uses std::getline() to read console input. The test simulates input
 * by redirecting std::cin and provides a string ("client\nquit\n") that first allows a client
 * connection and then instructs the demo to terminate.
 *
 * Additionally, a separate client thread is spawned to connect to the server. If the connection
 * succeeds, a flag is set. The test asserts that runDemo() returns 0 and that the client connection
 * was successfully established.
 *
 * @note This test uses the TEST_MODE macro. Ensure that your implementation of runDemo()
 *       (in io_and_sockets.cpp) is modified so that when TEST_MODE is defined, it reads input using
 *       std::getline() rather than using _kbhit() on Windows.
 */

#include "io_and_sockets/io_and_sockets.hpp"  // Adjust the path as needed.
#include <cassert>
#include <sstream>
#include <iostream>
#include <thread>
#include <atomic>
#ifdef _WIN32
    #include <winsock2.h>
    #pragma comment(lib, "Ws2_32.lib")
#else
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
#endif

// Port must match the one defined in io_and_sockets.cpp (e.g., 12345).
#ifndef PORT
#define PORT 12345
#endif

// Atomic flag to indicate a successful client connection.
std::atomic<bool> clientConnected{false};

/**
 * @brief Client thread function that attempts to connect to the server.
 *
 * The function waits briefly to allow the server to start up, then creates a client socket
 * and attempts to connect to localhost on PORT. If the connection succeeds, the atomic flag is set.
 */
void clientThreadFunction() {
    // Wait a short while to ensure the server is listening.
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

#ifdef _WIN32
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        return;
    }
#else
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return;
    }
#endif

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
#ifdef _WIN32
    serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
#else
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
#endif

    // Attempt to connect to the server.
#ifdef _WIN32
    int result = connect(sock, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (result != SOCKET_ERROR) {
        clientConnected = true;
    }
    closesocket(sock);
#else
    int result = connect(sock, reinterpret_cast<struct sockaddr*>(&serverAddr), sizeof(serverAddr));
    if (result == 0) {
        clientConnected = true;
    }
    close(sock);
#endif
}

int main() {
    // Prepare simulated input containing two lines: first "client", then "quit".
    // The demonstration will read "client" (which does nothing special) and then "quit" to terminate.
    std::istringstream simulatedInput("client\nquit\n");

    // Save the original std::cin stream buffer.
    std::streambuf* originalCinBuffer = std::cin.rdbuf();
    // Redirect std::cin to the simulated input.
    std::cin.rdbuf(simulatedInput.rdbuf());

    // Start the client thread to connect to the server.
    std::thread clientThread(clientThreadFunction);

    // Run the I/O and Sockets demonstration.
    int result = io_and_sockets::runDemo();

    // Wait for the client thread to finish.
    clientThread.join();

    // Restore the original std::cin stream buffer.
    std::cin.rdbuf(originalCinBuffer);

    // Verify that runDemo() returned 0 and the client successfully connected.
    assert(result == 0 && "runDemo() should return 0 when 'quit' is provided as input.");
    assert(clientConnected && "Client should have successfully connected to the server.");

    std::cout << "io_and_sockets test passed." << std::endl;
    return 0;
}
 