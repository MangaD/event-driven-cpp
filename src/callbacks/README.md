# Callbacks Example

This directory contains an example implementation of a simple callback mechanism in C++ using `std::function`. The example demonstrates how to set and trigger callbacks through an `Event` class, illustrating one approach to event-driven programming.

## Contents

- **callbacks.hpp**  
  Declares the `Event` class, which provides a mechanism to register a callback function (using `std::function<void()>`) and trigger it when needed.

- **callbacks.cpp**  
  Provides the implementation of the `Event` class methods. The `setCallback()` method assigns a callback function, and the `trigger()` method invokes the callback if it has been set.

- **main.cpp**  
  Contains a simple demonstration of the callback mechanism. In this example, an `Event` instance is created, a callback is set using a lambda expression, and the event is triggered to execute the callback.

- **CMakeLists.txt**  
  The CMake configuration file for building this example. It sets the C++20 standard, includes necessary directories (such as `src/common` if shared utilities are used), and creates an executable target named `callbacks_example`.

## Building the Example

To build the callbacks example:

1. **Navigate to the project root directory:**

   ```bash
   cd /path/to/event-driven-cpp
   ```

2. **Create a build directory and configure the project with CMake:**

   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Build the callbacks example:**

   On Unix-like systems, run:

   ```bash
   make callbacks_example
   ```

## Running the Example

After building, run the executable for the callbacks example. For instance:

```bash
./src/callbacks/callbacks_example
```

This will execute the program, which sets a callback that prints a message to the console, and then triggers the event to invoke the callback.

## Overview

The callbacks example is designed to illustrate a lightweight approach to handling asynchronous events or function calls using callbacks. The `Event` class encapsulates the callback mechanism, making it easy to decouple the registration of callback functions from their execution. This pattern is commonly used in event-driven programming to enable flexible, modular, and decoupled designs.

Feel free to modify and extend this example to experiment with different callback scenarios and integrate it into larger projects.
