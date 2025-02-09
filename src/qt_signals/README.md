# Qt Signals & Slots Example

This directory contains an example implementation demonstrating event-driven programming using Qt's signals and slots mechanism in C++. The example shows how to declare signals and slots in a Qt class, connect them, and emit signals to notify the corresponding slots.

## Contents

- **qt_signals.hpp**  
  Declares the `QtSignalsExample` class, which uses the Q_OBJECT macro to enable signals and slots. It defines a signal (`mySignal`) and a corresponding slot (`onMySignal`).

- **qt_signals.cpp**  
  Implements the `QtSignalsExample` class, including the logic to emit the signal and handle it in the slot.

- **main.cpp**  
  Contains a simple application that creates an instance of `QtSignalsExample`, connects its signal to its slot, and emits the signal to demonstrate the event-driven behavior.

- **CMakeLists.txt**  
  Configures the build for the Qt signals & slots example. On Windows, a post-build command automatically runs `windeployqt` to copy the necessary Qt DLLs to the executable’s directory.

## Building the Example

### Prerequisites

- **Qt6:** Ensure that Qt6 is installed and that the `Qt6_DIR` variable is correctly set. The default in the CMake presets is set to `C:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6`, but you may need to modify this path depending on your system configuration.
- **C++ Compiler:** A compiler with C++20 support (e.g., GCC, Clang, or MSVC).
- **CMake:** Version 3.19 or later.
- **Build Tools:** Ninja, Visual Studio, or your preferred generator supported by CMake.

### Build Steps

1. **Configure the Project:**  
   From the project root, use the provided CMake presets or run a configuration command manually. For example, for Windows MSVC Debug:
   ```bash
   cmake --preset windows-msvc-debug
   ```

2. **Build the Project:**  
   After configuration, build the project:
   ```bash
   cmake --build --preset windows-msvc-debug
   ```
   On Windows, the post-build step will automatically invoke `windeployqt` to deploy the required Qt DLLs.

## Running the Example

After building, run the executable from the build directory. For example:

- **On Windows:**
  ```powershell
  .\src\qt_signals\Debug\qt_signals_example.exe
  ```
- **On Linux/macOS:**
  ```bash
  ./src/qt_signals/qt_signals_example
  ```

## Overview of the Example

This example demonstrates:
- **Declaring Signals and Slots:**  
  Using the `Q_OBJECT` macro in the `QtSignalsExample` class to enable Qt’s meta-object system.
- **Connecting Signals to Slots:**  
  Establishing connections so that when a signal is emitted, the corresponding slot is called.
- **Emitting Signals:**  
  Calling the `emitSignal()` method to trigger the signal and observing how the connected slot processes the signal (e.g., printing a message to the console).

## Additional Resources

For more information on Qt's signals and slots mechanism, refer to the [official Qt documentation](https://doc.qt.io/qt-6/signalsandslots.html).
