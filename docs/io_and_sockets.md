# I/O and Sockets Demonstration

This document explains the demonstration example that monitors both asynchronous I/O events and socket events in a cross-platform manner. The example is implemented in the `io_and_sockets` directory and uses platform-specific techniques to monitor both console input and a TCP server socket.

---

## Overview

The demonstration sets up a TCP server socket that listens on port **12345** for incoming connections and, at the same time, monitors console input for user commands. Depending on the platform, the implementation uses:

- **POSIX Systems:**  
  The `select()` system call is used to monitor both the server socket and standard input (STDIN_FILENO). When either the socket or the console input is ready, the appropriate action is taken.

- **Windows:**  
  Winsock’s `select()` function is used to monitor the server socket, while the `_kbhit()` function is used in a polling loop to check for console input because the standard Windows console input is not directly compatible with `select()`.

The demonstration runs continuously until the user types **"quit"** in the console, at which point the server shuts down gracefully.

---

## Key Features

- **Cross-Platform Socket Programming:**  
  Demonstrates how to create, bind, and listen on a TCP server socket on both Windows and POSIX systems.

- **Event Monitoring:**  
  Uses `select()` on POSIX to monitor multiple file descriptors and a combination of Winsock’s `select()` and `_kbhit()` on Windows to monitor both socket events and console input.

- **Graceful Shutdown:**  
  Allows the user to type **"quit"** to exit the demonstration, ensuring that resources such as sockets are properly released.

---

## Implementation Details

- **TCP Server Socket:**  
  A TCP server socket is created and bound to `INADDR_ANY` on port 12345, allowing it to accept connections from any network interface.

- **Event Loop:**  
  The application enters a loop where:
  - On **POSIX**, `select()` monitors both the server socket and the standard input file descriptor.
  - On **Windows**, Winsock’s `select()` monitors the server socket, and `_kbhit()` is used to check if a key has been pressed in the console.
  
- **Connection Handling:**  
  When the server socket indicates an incoming connection, the server accepts the connection, prints a message, and then closes the client socket immediately.

- **Console Input:**  
  When console input is detected, the input is read and printed. If the user enters **"quit"**, the loop terminates, and the server shuts down.

- **Platform-Specific Considerations:**  
  On Windows, Winsock initialization (via `WSAStartup()`) and cleanup (`WSACleanup()`) are performed. On POSIX, standard system calls are used for socket and I/O operations.

---

## How to Build and Run

### Building the Demonstration

1. **Configure and Build:**

   Use the provided CMake presets or configure manually. For example, with CMake presets:
   ```bash
   cmake --preset <your-preset>
   cmake --build --preset <your-preset>
   ```
   Replace `<your-preset>` with your chosen configuration, such as `windows-msvc-debug` or `linux-gcc-debug`.

2. **Executable Location:**

   The built executable will be located in the build directory, for example:
   - On Windows: `./src/io_and_sockets/Debug/io_and_sockets_example.exe`
   - On Linux/macOS: `./src/io_and_sockets/io_and_sockets_example`

### Running the Demonstration

- **On Windows:**  
  Open a Command Prompt or PowerShell, navigate to the build directory, and run:
  ```powershell
  .\src\io_and_sockets\Debug\io_and_sockets_example.exe
  ```
  
- **On Linux/macOS:**  
  From the build directory, run:
  ```bash
  ./src/io_and_sockets/io_and_sockets_example
  ```

### Interacting with the Demonstration

- The server will print a message indicating that it is listening on port 12345.
- If a client connects (for example, via `telnet localhost 12345`), the server will print a message indicating a connection was accepted.
- Any console input will be echoed back.  
- Typing **"quit"** (without quotes) in the console will gracefully shut down the server and exit the demonstration.

---

## Additional Resources

- **POSIX select() Documentation:**  
  [man7.org/linux/man-pages/man2/select.2.html](https://man7.org/linux/man-pages/man2/select.2.html)

- **Winsock select() Documentation:**  
  [MSDN Winsock select()](https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-select)

- **_kbhit() on Windows:**  
  [MSDN _kbhit()](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/kbhit)

---

This document provides a detailed explanation of the I/O and Sockets demonstration, which is designed to illustrate cross-platform event monitoring using both socket and console I/O. Enjoy exploring and modifying the example for your needs!
