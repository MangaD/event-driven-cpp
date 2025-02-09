# Event Queue Example

This directory contains an example implementation of a thread-safe event queue in C++. The event queue is designed to decouple event production from event processing, making it useful in event-driven architectures, game loops, or any asynchronous application. Each event is represented as a callable object (`std::function<void()>`), and the queue processes events in a FIFO (first-in, first-out) manner.

---

## Contents

- **event_queue.hpp**  
  Declares the `EventQueue` class, which provides methods for enqueuing events, processing them, and checking if the queue is empty.

- **event_queue.cpp**  
  Implements the `EventQueue` class. It handles thread-safe insertion of events and processing of queued events.

- **main.cpp**  
  A demonstration program that enqueues several events (using lambda functions) and then processes them in FIFO order, printing messages to the console.

- **CMakeLists.txt**  
  Contains the CMake build configuration for this example.

---

## Building the Example

This example is built using CMake. You can either use the provided CMake presets (if available) or manually configure and build the project.

### Manual Build Steps

1. **Create a Build Directory and Configure:**

   Open a terminal in the project root and run:

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

## Running the Example

After building, run the executable from the build output directory. For example:

- **On Windows:**

  ```powershell
  .\src\event_queue\Debug\event_queue_example.exe
  ```

- **On Linux/macOS:**

  ```bash
  ./src/event_queue/event_queue_example
  ```

When executed, the program enqueues several events that print messages to the console and then processes them. The output should display the messages in the order the events were added to the queue.

---

## Overview

This example demonstrates:
- **Thread-Safe Event Queuing:**  
  Using `std::queue`, `std::mutex`, and `std::lock_guard` to safely manage events across multiple threads.
- **Decoupled Event Processing:**  
  Separating the production of events from their consumption allows flexible and scalable system design.
- **FIFO Processing:**  
  Ensuring that events are processed in the order they were enqueued.

Feel free to modify or extend this example to suit your needs, such as adding events from multiple threads or integrating additional functionality.

---

## License

This project is licensed under the MIT License. See the [LICENSE](../../LICENSE) file for details.
