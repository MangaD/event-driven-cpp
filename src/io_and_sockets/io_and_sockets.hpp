#ifndef IO_AND_SOCKETS_HPP
#define IO_AND_SOCKETS_HPP

/**
 * @file io_and_sockets.hpp
 * @brief Declaration of the runDemo() function for the I/O and Sockets demonstration.
 *
 * This header declares the runDemo() function which sets up and runs the
 * demonstration for monitoring both socket events and console input.
 * The demonstration creates a TCP server that listens on a specific port and
 * continuously processes events until the user types "quit".
 */

/**
 * @namespace io_and_sockets
 * @brief Provides cross-platform functionality for monitoring I/O and socket events.
 *
 * This namespace contains functions and classes that enable the creation and management of a TCP server
 * socket along with the monitoring of console input. It is designed to work on both Windows and POSIX systems.
 *
 * On POSIX systems, the implementation uses the standard socket APIs and the select() system call to monitor
 * both the server socket and the standard input (STDIN_FILENO). On Windows, Winsock’s select() function is used
 * to monitor the server socket while console input is handled either by polling with _kbhit() or, when in test
 * mode (TEST_MODE defined), by using standard input functions like std::getline().
 *
 * The primary function provided in this namespace is runDemo(), which sets up the server, enters an event loop,
 * and gracefully terminates when the user inputs the "quit" command.
 */
namespace io_and_sockets {

/**
 * @brief Run demo for the I/O and socket monitoring example.
 *
 * This function sets up a TCP server socket, binds it to port 12345, and begins listening
 * for incoming connections. It then enters a loop that monitors:
 * - The server socket for incoming connection requests.
 * - Console input for user commands.
 *
 * On Windows, the server socket is monitored using Winsock’s `select()` while console input
 * is polled using `_kbhit()`. On POSIX systems, the `select()` system call monitors both the
 * server socket and the standard input file descriptor.
 *
 * Typing "quit" in the console will terminate the loop and shut down the server.
 *
 * @return int Returns 0 upon successful termination.
 */
int runDemo();

} // namespace io_and_sockets

#endif // IO_AND_SOCKETS_HPP
