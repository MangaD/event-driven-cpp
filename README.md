# Event-Driven Programming in C++

[![CI](https://github.com/MangaD/event-driven-cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/MangaD/event-driven-cpp/actions/workflows/ci.yml) [![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-published-brightgreen)](https://mangad.github.io/event-driven-cpp) [![pipeline status](https://gitlab.com/MangaD/event-driven-cpp/badges/main/pipeline.svg)](https://gitlab.com/MangaD/event-driven-cpp/-/pipelines)
[![GitLab Pages](https://img.shields.io/badge/GitLab%20Pages-published-brightgreen)](https://MangaD.gitlab.io/event-driven-cpp/)


*Disclaimer: This project was built collaboratively with AI, step by step. Its primary purpose is to serve as an educational tool for studying and understanding event-driven programming in C++.*

This repository is a case study demonstrating various approaches to event-driven programming in C++. It includes examples implemented in C++ using different design patterns and libraries such as:

- The **Observer pattern** for decoupled event notifications.
- **Callbacks** using `std::function` to handle asynchronous events.
- **Qt Signals & Slots** to leverage Qt’s robust event-driven system.
- **I/O and Sockets** for cross-platform asynchronous I/O and socket programming, using system calls (like `select()`) on POSIX systems and platform-specific alternatives on Windows.
- An **Event Queue** implementation to decouple event production from processing in a thread-safe manner.

## Prerequisites

Before building and running the project, ensure you have the following installed:

- **C++ Compiler:** A modern C++ compiler supporting C++20 (e.g., GCC 10+, Clang 10+, or MSVC 2019/2022).
- **CMake:** Version 3.19 or later (to take advantage of CMake Presets).
- **Git:** For cloning the repository.
- **Qt6:** Installed on your system.  
  **Note:** The CMake presets assume a default path (e.g., `C:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6` on Windows); you may need to modify the `Qt6_DIR` variable in `CMakePresets.json` to match your installation.
- **Build Tools:** Ninja, Visual Studio, or another supported generator.

## Building the Project

The project uses CMake with presets defined in `CMakePresets.json` to streamline configuration and building across multiple platforms and build types.

### Configuration

For example, to configure the project:
- **Default (cross-platform):**
  ```bash
  cmake --preset default
  ```
- **Windows MSVC Debug:**
  ```bash
  cmake --preset windows-msvc-debug
  ```
- **Linux GCC Debug:**
  ```bash
  cmake --preset linux-gcc-debug
  ```

### Building

After configuration, build the project using:
```bash
cmake --build --preset <preset>
```
Replace `<preset>` with your chosen configuration (e.g., `windows-msvc-debug` or `linux-gcc-debug`).

On Windows, post-build steps (such as running `windeployqt` for Qt-based examples) are executed automatically.

## Running the Examples

Each example is built as a separate executable:
- **Observer, Callbacks, Qt Signals & Slots, I/O and Sockets,** and **Event Queue** examples are all provided.
- Run the desired executable from its build directory (e.g., via the command line or your IDE).

## Running the Tests

Unit tests are located in the `tests` directory and are registered via CTest. To run all tests:
1. Navigate to your build directory.
2. Run:
   ```bash
   ctest --preset <preset> --verbose -C <configuration>
   ```
   For example, on Windows:
   ```bash
   ctest --preset windows-msvc-debug --verbose -C Debug
   ```

## Test Mode for I/O and Sockets Example

For automated testing, the I/O and Sockets demonstration supports a `TEST_MODE` macro. When defined, the Windows-specific code bypasses the `_kbhit()` polling and reads console input using `std::getline()`. This allows tests to simulate input automatically (for example, by redirecting `std::cin`) so that manual intervention isn’t required.

## Additional Notes

- **Temporary Directories:**  
  The testing process may create a `Testing/Temporary` directory as part of CTest’s internal workflow. This is normal and can be ignored.
  
- **Qt DLL Deployment on Windows:**  
  The Qt-based examples automatically run `windeployqt` as a post-build step on Windows to deploy the required Qt DLLs.

- **Customization:**  
  You are welcome to modify or extend any of the examples to suit your needs.

## Contributing

Contributions, improvements, and bug fixes are welcome! Please submit pull requests or open issues to help enhance the project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
