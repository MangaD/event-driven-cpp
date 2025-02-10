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

namespace io_and_sockets {

/**
 * @brief Runs the I/O and Sockets demonstration.
 *
 * This function sets up a TCP server socket, monitors socket events and console input,
 * and continues to run until the user enters "quit" on the console. It returns 0 upon
 * successful termination.
 *
 * @return int The exit code of the demonstration (0 on success).
 */
int runDemo();

} // namespace io_and_sockets

#endif // IO_AND_SOCKETS_HPP
