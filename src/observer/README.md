# Observer Pattern Example

This directory contains an implementation of the Observer pattern in C++ as a demonstration of event-driven programming. The Observer pattern enables one object (the Subject) to notify multiple dependent objects (Observers) about events or state changes without tightly coupling the subject to the observers.

## Contents

- **observer.hpp**  
  Declares the `IObserver` interface that defines the contract for all observers. Any class that wants to receive notifications should implement this interface.

- **subject.hpp**  
  Defines the `Subject` class, which manages a list of observers and provides methods to add, remove, and notify them of events.

- **main.cpp**  
  A sample program that demonstrates the Observer pattern in action. It creates a subject, registers concrete observers, sends notifications, and shows how observers are notified.

- **CMakeLists.txt**  
  The CMake configuration file for building the observer example. It sets the C++ standard, includes necessary directories, and builds the executable.

## Building the Example

To build the observer example:

1. **Navigate to the Project Root:**

   ```bash
   cd /path/to/event-driven-cpp
   ```

2. **Create a Build Directory and Configure the Project:**

   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Build the Observer Example:**

   ```bash
   make observer_example
   ```

## Running the Example

After building, you can run the observer example by executing the generated binary:

```bash
./src/observer/observer_example
```

This will launch the example program, which demonstrates how the subject notifies its observers when an event occurs.

## Overview of the Observer Pattern

The Observer pattern is a key design pattern for event-driven programming. It allows a subject to notify multiple observers about events or changes in its state while maintaining loose coupling between the subject and its observers. This example illustrates a simple implementation that can be extended or integrated into larger applications.

---

Feel free to modify or extend this example to fit your specific needs.
