# Event-Driven Programming in C++

Event-Driven Programming in C++ is a case study project that demonstrates multiple approaches to handling events and asynchronous behavior in C++. This repository includes examples of different techniques and design patterns used for event-driven programming, each implemented in its own subproject.

## Overview

This project provides examples of:

- **Observer Pattern:**  
  A classic design pattern for decoupled event handling.
- **Callbacks:**  
  Implementation using function pointers, lambdas, and `std::function`.
- **Qt Signals & Slots:**  
  Leveraging the Qt framework for a built-in signal-slot mechanism.
- **I/O Events:**  
  Handling asynchronous I/O with system calls like `select()` and `poll()`.
- **Event Queue:**  
  Implementing a message queue to manage asynchronous events.

## Project Structure

```
event-driven-cpp/
├── docs/                  
│   ├── README.md                        # Documentation overview
│   ├── observer.md                      # Observer pattern explanation
│   ├── callbacks.md                     # Callbacks explanation
│   ├── qt_signals.md                    # Qt signals & slots explanation
│   ├── io_events.md                     # I/O event handling explanation
│   ├── event_queue.md                   # Event queue explanation
│   ├── event_driven_comparison.md       # Comparison of event-driven programming in various languages
│   ├── setup.md                         # Build and run instructions
│   └── design.md                        # Design considerations
│
├── src/                   # Source code for each event mechanism example
│   ├── observer/          # Observer pattern example
│   │   ├── observer.hpp
│   │   ├── observer.cpp
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── README.md
│   │
│   ├── callbacks/         # Callbacks example
│   │   ├── callbacks.hpp
│   │   ├── callbacks.cpp
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── README.md
│   │
│   ├── qt_signals/        # Qt signals & slots example
│   │   ├── qt_signals.hpp
│   │   ├── qt_signals.cpp
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── README.md
│   │
│   ├── io_events/         # I/O event handling example
│   │   ├── io_events.hpp
│   │   ├── io_events.cpp
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── README.md
│   │
│   ├── event_queue/       # Event queue example
│   │   ├── event_queue.hpp
│   │   ├── event_queue.cpp
│   │   ├── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── README.md
│   │
│   └── common/            # Shared utilities (if any)
│       ├── logger.hpp
│       ├── logger.cpp
│       ├── CMakeLists.txt
│       └── README.md
│
├── tests/                 # Unit tests for each implementation
│   ├── observer_test.cpp
│   ├── callbacks_test.cpp
│   ├── qt_signals_test.cpp
│   ├── io_events_test.cpp
│   ├── event_queue_test.cpp
│   ├── CMakeLists.txt
│
├── .clang-format          # Code formatting rules
├── .gitignore             # Git ignore file
├── LICENSE                # Project license
├── README.md              # This file
└── CMakeLists.txt         # Root CMake configuration
```

## Prerequisites

Before building the project, ensure you have the following installed:

- **C++ Compiler:** A compiler with C++20 support (e.g., GCC 10+, Clang 10+, or MSVC).
- **CMake:** Version 3.10 or later.
- **Git:** To clone the repository.
- **Optional:**
  - **Qt:** Required for the Qt signals & slots example.
  - **clang-format:** For code formatting (see `.clang-format`).

## Building the Project

Follow these steps to build the project:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/event-driven-cpp.git
   cd event-driven-cpp
   ```

2. **Create a Build Directory:**

   ```bash
   mkdir build
   cd build
   ```

3. **Generate Build Files with CMake:**

   ```bash
   cmake ..
   ```

4. **Build the Project:**

   On Unix-like systems, run:

   ```bash
   make
   ```

   On Windows, open the generated solution in Visual Studio or use the appropriate build tool.

## Running the Examples

Each subproject in the `src/` directory comes with its own example and a corresponding `README.md`. After building the project, you can run the executables found in the build output. For example:

- **Observer Pattern Example:** `build/src/observer/observer_example`
- **Callbacks Example:** `build/src/callbacks/callbacks_example`
- **Qt Signals & Slots Example:** `build/src/qt_signals/qt_signals_example` (requires Qt)
- **I/O Events Example:** `build/src/io_events/io_events_example`
- **Event Queue Example:** `build/src/event_queue/event_queue_example`

## Running Tests

Unit tests are provided in the `tests/` directory. To run the tests:

1. Navigate to the `build` directory.
2. Execute:

   ```bash
   ctest --verbose
   ```

## Documentation

Comprehensive documentation is available in the `docs/` directory, covering:

- **Observer Pattern:** `docs/observer.md`
- **Callbacks:** `docs/callbacks.md`
- **Qt Signals & Slots:** `docs/qt_signals.md`
- **I/O Events:** `docs/io_events.md`
- **Event Queue:** `docs/event_queue.md`
- **Event-Driven Comparison:** `docs/event_driven_comparison.md`
- **Setup Instructions:** `docs/setup.md`
- **Design Considerations:** `docs/design.md`

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! If you have improvements, new examples, or suggestions, please open a pull request or submit an issue.
