# Setup Guide for Event-Driven Programming in C++

This guide explains how to set up, build, and run the Event-Driven Programming in C++ project across multiple platforms using CMake and CMake Presets. The project includes examples of various event-driven techniques, including a Qt signals & slots example. On Windows, a post-build command automatically runs `windeployqt` to deploy the necessary Qt DLLs, so you don't have to run it manually.

---

## Prerequisites

Before you begin, ensure you have the following installed:

- **C++ Compiler:** A compiler supporting C++20 (e.g., GCC, Clang, or MSVC).
- **CMake:** Version 3.19 or later (to support CMake Presets).
- **Git:** For cloning the repository.
- **Qt6:** Installed on your system.
  - **Windows:** e.g., `C:\Qt\6.8.2\msvc2022_64\`
  - **Linux/macOS:** Ensure Qt6 is installed and accessible.
- **Build Tool:** Ninja, Visual Studio, or another generator supported by CMake.

---

## Cloning the Repository

Clone the repository from GitHub and navigate into the project directory:

```bash
git clone https://github.com/MangaD/event-driven-cpp.git
cd event-driven-cpp
```

---

## Using CMake Presets

The project includes a `CMakePresets.json` file in the root directory that defines several configuration presets for cross-platform builds and multiple build types.

### To Configure the Project

For a default cross-platform configuration, run:

```bash
cmake --preset default
```

For Windows MSVC in Debug mode, for example:

```bash
cmake --preset windows-msvc-debug
```

### To Build the Project

After configuration, build using:

```bash
cmake --build --preset default
```

Or, for a specific preset (e.g., Windows MSVC Debug):

```bash
cmake --build --preset windows-msvc-debug
```

---

## Automatic Deployment on Windows

For the Qt signals & slots example, the CMakeLists.txt file in `src/qt_signals` includes a post-build custom command that runs `windeployqt` automatically. This step copies all required Qt6 DLLs into your build directory alongside the executable. You no longer need to manually run `windeployqt`.

### Note on Qt6_DIR

The `Qt6_DIR` variable in the CMake presets (or your environment) must point to the directory containing the Qt6 CMake configuration files (typically something like `C:/Qt/<version>/<compiler>/lib/cmake/Qt6` on Windows). If your Qt installation is located elsewhere, please update this variable accordingly in the `CMakePresets.json` file or your environment.


---

## Running the Application

After building, run the executable from the build output directory:

- **On Windows:**

  The post-build command will have deployed the Qt DLLs automatically. For example:

  ```powershell
  .\src\qt_signals\Debug\qt_signals_example.exe
  ```

- **On Linux/macOS:**

  Run the executable from the build directory:

  ```bash
  ./src/qt_signals/qt_signals_example
  ```

If you run into issues with missing DLLs on Windows, verify that the post-build command has executed successfully and that your `Qt6_DIR` is correctly configured.

---

## Summary

1. **Clone the Repository:**  
   Use Git to clone the project and change into its directory.

2. **Configure and Build:**  
   Use the provided `CMakePresets.json` with the `cmake --preset` and `cmake --build` commands to configure and build the project.

3. **Automatic Deployment (Windows):**  
   The post-build custom command runs `windeployqt` to deploy the necessary Qt DLLs automatically.

4. **Run the Executable:**  
   Launch the desired example from your build output directory.

Following these steps should provide a streamlined, cross-platform workflow for building and running the Event-Driven Programming in C++ project without manually hardcoding paths or running deployment commands.
