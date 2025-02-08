# Common Utilities

This folder contains shared utilities for the Event-Driven Programming in C++ project. Currently, the library includes a simple logging utility that can be used by various components throughout the project.

## Contents

- **logger.hpp & logger.cpp**  
  A lightweight logging utility that provides methods for logging messages at different levels (Debug, Info, Warning, and Error). The logger is defined within the `common` namespace and allows you to set the current log level to control which messages are output.

- **CMakeLists.txt**  
  The CMake configuration file for building the common utilities library. This library can be linked by other subprojects that require shared functionality.

## Usage

To use the logging functionality in your code, include the header file and link against the `common` library. For example:

```cpp
#include "logger.hpp"

int main() {
    // Set the logging level to Debug to enable all log messages.
    common::Logger::setLogLevel(common::LogLevel::Debug);
    
    common::Logger::debug("This is a debug message.");
    common::Logger::info("This is an info message.");
    common::Logger::warning("This is a warning message.");
    common::Logger::error("This is an error message.");

    return 0;
}
```

## Building

The common utilities library is built as part of the overall project using the root `CMakeLists.txt`. It can also be built independently by navigating to this directory and running CMake:

```bash
mkdir build
cd build
cmake ..
make
```

This will compile the `common` library, which can then be linked with other parts of the project.

## License

This project is licensed under the MIT License. See the [LICENSE](../../LICENSE) file for details.
