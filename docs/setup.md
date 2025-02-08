# Setup Guide for Event-Driven Programming in C++

This guide explains how to set up, build, and run the **Event-Driven Programming in C++** project. The project uses CMake for configuration and building.

## Prerequisites

Before you begin, ensure you have the following installed:
- **C++ Compiler:** A compiler supporting C++20 (e.g., GCC 10+, Clang 10+, or MSVC).
- **CMake:** Version 3.10 or later.
- **Git:** To clone the repository.
- **Optional: clang-format** for code formatting (refer to the `.clang-format` file).
- **Optional: Qt:** Required only if you plan to build the Qt signals & slots example (Qt 5 or Qt 6).

## Cloning the Repository

Open a terminal and run:

```bash
git clone https://github.com/yourusername/event-driven-cpp.git
cd event-driven-cpp
```

Replace `yourusername` with your actual GitHub username.

## Building the Project

This project uses CMake. Follow these steps to build the entire project:

1. **Create a Build Directory:**

   ```bash
   mkdir build
   cd build
   ```

2. **Generate Build Files:**

   Run the following command to generate the build files (the project is configured to use C++20 as defined in the root `CMakeLists.txt`):

   ```bash
   cmake ..
   ```

3. **Build the Project:**

   On Unix-like systems, run:

   ```bash
   make
   ```

   On Windows (using Visual Studio or a similar generator), build the generated solution files accordingly.

## Running the Examples

The project contains several examples in the `src/` directory. Each subproject has its own `README.md` with further details. Some common examples include:

- **Observer Pattern Example:**
  - Executable (e.g., `observer_example`) is located in `src/observer/`.

- **Callbacks Example:**
  - Executable (e.g., `callbacks_example`) is located in `src/callbacks/`.

- **Qt Signals & Slots Example:**
  - Executable (e.g., `qt_signals_example`) is located in `src/qt_signals/`.
  - Ensure that Qt is installed on your system.

- **I/O Events Example:**
  - Executable (e.g., `io_events_example`) is located in `src/io_events/`.

- **Event Queue Example:**
  - Executable (e.g., `event_queue_example`) is located in `src/event_queue/`.

To run an example, navigate to the corresponding build output directory (inside `build/`) and execute the generated binary.

## Running Tests

Unit tests for various implementations are provided in the `tests/` directory. To run the tests:

1. **Ensure Tests Are Built:**
   - When you build the project from the root, the tests are compiled as well.

2. **Execute the Tests Using CTest:**

   From the `build` directory, run:

   ```bash
   ctest --verbose
   ```

This command will run all tests and display detailed output.

## Code Formatting

To format the code manually using `clang-format`, you can run the following command on individual files:

```bash
clang-format -i path/to/your/file.cpp
```

For more information on the formatting rules, see the `.clang-format` file in the project root.

## Conclusion

By following these steps, you should be able to set up, build, and run the examples in this project. If you encounter any issues, please refer to the documentation in the `docs/` directory or the `README.md` files within each subproject in the `src/` directory.
