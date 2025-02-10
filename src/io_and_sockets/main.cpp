/**
 * @file main.cpp
 * @brief Entry point for the I/O and Sockets demonstration.
 *
 * This program serves as the entry point for the demonstration of cross-platform I/O and
 * socket event monitoring. It leverages the functionality provided in the io_and_sockets
 * module, which sets up a TCP server that listens on a fixed port (e.g., 12345) and monitors
 * for both incoming socket connections and console input. The demonstration continues until
 * the user types "quit", after which the server shuts down gracefully.
 *
 * @return int Returns 0 upon successful termination.
 */
#include "io_and_sockets.hpp"

int main() {
    return io_and_sockets::runDemo();
}
