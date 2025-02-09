# Event-Driven Programming in C++

This repository is a case study demonstrating various approaches to event-driven programming in C++. It includes examples implemented in C++ using different design patterns and libraries such as:

- The **Observer pattern** for decoupled event notifications.
- **Callbacks** using `std::function` to handle events.
- **Qt Signals & Slots** to leverage Qt’s robust event-driven system.
- **I/O and Sockets** for cross-platform asynchronous I/O and socket programming, using system calls like `select()`/`poll()` on POSIX systems and platform-specific alternatives on Windows.
- An **Event Queue** implementation to decouple event production from consumption.

The project is cross-platform, supports multiple compilers and build types, and uses CMake (with CMake Presets) to simplify configuration and build management.

---

## Project Structure

```
event-driven-cpp/
├── docs/                  
│   ├── README.md                        # This documentation overview
│   ├── observer.md                      # Observer pattern explanation
│   ├── callbacks.md                     # Callbacks explanation
│   ├── qt_signals.md                    # Qt signals & slots explanation
│   ├── io_and_sockets.md                # I/O & sockets explanation
│   ├── event_queue.md                   # Event queue implementation explanation
│   ├── event_driven_comparison.md       # Comparison of event-driven programming in various languages
│   ├── setup.md                         # Setup and build instructions
│   └── design.md                        # Design considerations
│
├── src/                   # Source code for each example
│   ├── observer/          # Observer pattern example
│   │   ├── observer.hpp
│   │   ├── subject.hpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── callbacks/         # Callbacks example
│   │   ├── callbacks.hpp
│   │   ├── callbacks.cpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── qt_signals/        # Qt signals & slots example
│   │   ├── qt_signals.hpp
│   │   ├── qt_signals.cpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── io_and_sockets/    # I/O and sockets example
│   │   ├── io_and_sockets.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── event_queue/       # Event queue example
│   │   ├── event_queue.hpp
│   │   ├── event_queue.cpp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   │
│   └── common/            # Shared utilities
│       ├── logger.hpp
│       ├── logger.cpp
│       └── CMakeLists.txt
│
├── tests/                 # Unit tests for each implementation
│   ├── observer_test.cpp
│   ├── callbacks_test.cpp
│   ├── qt_signals_test.cpp
│   ├── io_and_sockets_test.cpp
│   ├── event_queue_test.cpp
│   └── CMakeLists.txt
│
├── CMakePresets.json      # Presets for cross-platform configuration/build
├── .clang-format          # Code formatting rules
├── .gitignore             # Git ignore file
├── LICENSE                # Project license (MIT)
└── CMakeLists.txt         # Top-level CMake configuration
```

---

## Prerequisites

Before building this project, ensure you have the following installed:

- **C++ Compiler:** A modern C++ compiler supporting C++20 (e.g., GCC 10+, Clang 10+, or MSVC 2019/2022).
- **CMake:** Version 3.19 or later (for CMake Presets support).
- **Git:** To clone the repository.
**Qt6:** Installed on your system (Note: The `Qt6_DIR` variable in the CMake presets is set to a default path—e.g., `C:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6` on Windows. You may need to modify this path to match your Qt installation. The `VCINSTALLDIR` environment variable should also be set to the Visual Studio installation directory).
  - On **Windows**, a typical installation might be at `C:\Qt\6.8.2\msvc2022_64\`.
  - On **Linux/macOS**, ensure that Qt6 is installed and accessible (e.g., via your package manager or from the Qt website).
- **Build Tools:** Ninja, Visual Studio, or your preferred generator supported by CMake.

---

## Setup and Build Instructions

### Using CMake Presets

The project includes a `CMakePresets.json` file for streamlined configuration and building across different platforms and compilers.

1. **Configure the Project:**

   - For a default configuration (cross-platform), run:
     ```bash
     cmake --preset default
     ```
   - For a specific configuration (e.g., Windows MSVC Debug):
     ```bash
     cmake --preset windows-msvc-debug
     ```

2. **Build the Project:**

   - After configuration, build using:
     ```bash
     cmake --build --preset default
     ```
     Or, for a specific preset:
     ```bash
     cmake --build --preset windows-msvc-debug
     ```

### Automatic Deployment on Windows

For the Qt signals & slots example, the CMakeLists.txt in `src/qt_signals` has a post-build custom command that automatically runs `windeployqt` to copy the required Qt DLLs to the executable’s folder. This eliminates the need for manually running `windeployqt`.

### Running the Applications

- **On Windows:**  
  After building, run the executables from the appropriate build directory. For example:
  ```powershell
  .\src\qt_signals\Debug\qt_signals_example.exe
  ```
  (The post-build command ensures that the required Qt DLLs are deployed automatically.)

- **On Linux/macOS:**  
  Simply run the executable from the build directory:
  ```bash
  ./src/qt_signals/qt_signals_example
  ```

---

## Running Tests

Unit tests are provided in the `tests/` directory. To run the tests:

1. Navigate to the build directory.
2. Execute:
   ```bash
   ctest --verbose
   ```

---

## Contributing

Contributions are welcome! If you have improvements, bug fixes, or additional examples, please submit a pull request or open an issue.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
