# I/O and Sockets Demonstration

This directory contains a cross-platform demonstration that monitors both socket events and console input. The demonstration sets up a simple TCP server socket (listening on port 12345) and continuously monitors for:

- **Incoming connections on the server socket**, and
- **Console input** (e.g., user commands such as "quit" to stop the server).

The implementation uses different techniques depending on the platform:

- **Windows:**  
  Uses Winsock’s `select()` function to monitor the server socket and `_kbhit()` to poll for console input.
- **POSIX (Linux/macOS):**  
  Uses the `select()` system call to monitor both the server socket and standard input (STDIN_FILENO).

---

## Contents

- **io_and_sockets.cpp**  
  Implements the demonstration. This file sets up the TCP server socket, enters a loop to monitor socket and console events, and handles incoming connections and user input.

- **CMakeLists.txt**  
  Contains the CMake build configuration for this demonstration. It supports cross-platform builds and links against necessary libraries (e.g., `ws2_32` on Windows for Winsock).

---

## Building the Demonstration

This demonstration is built using CMake. You can use the provided CMake presets for cross-platform configurations or run the commands manually.

### Using CMake Presets

For example, to build on Windows using MSVC in Debug mode:
```bash
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
```

For Linux with GCC in Debug mode:
```bash
cmake --preset linux-gcc-debug
cmake --build --preset linux-gcc-debug
```

### Manual Build Steps

1. **Create a Build Directory and Configure:**
   ```bash
   mkdir build
   cd build
   cmake ..
   ```
2. **Build the Project:**
   ```bash
   cmake --build .
   ```

---

## Running the Demonstration

After building, run the executable from the build output directory:

- **On Windows:**
  ```powershell
  .\src\io_and_sockets\Debug\io_and_sockets_example.exe
  ```
- **On Linux/macOS:**
  ```bash
  ./src/io_and_sockets/io_and_sockets_example
  ```

When the demonstration runs, you will see console messages indicating:
- That the server is listening on port 12345.
- When a connection is accepted on the server socket.
- Any console input entered by the user.

Type `"quit"` (without quotes) in the console and press Enter to gracefully shut down the server and exit the demonstration.

---

## Additional Information

This demonstration illustrates:
- **Cross-Platform Socket Programming:**  
  How to create and manage a TCP server socket using Winsock on Windows and POSIX sockets on Linux/macOS.
- **Event Monitoring:**  
  How to monitor multiple event sources (sockets and console input) using platform-specific techniques such as `select()` and `_kbhit()`.
- **Conditional Compilation:**  
  How to use preprocessor directives to write code that works on multiple platforms.

Feel free to modify and extend this example. You might experiment with handling multiple concurrent client connections or integrating additional I/O event sources.
