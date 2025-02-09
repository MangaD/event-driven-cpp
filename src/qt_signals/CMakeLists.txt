cmake_minimum_required(VERSION 3.10)

project(qt_signals_example)

# Set C++20 standard and enforce its use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt's automatic processing of MOC, UIC, and RCC files.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find the required Qt6 components.
find_package(Qt6 REQUIRED COMPONENTS Core)

# Include the common utilities directory (if needed).
include_directories(${CMAKE_SOURCE_DIR}/src/common)

# Add the executable target for the Qt signals & slots example.
add_executable(qt_signals_example
    main.cpp
    qt_signals.cpp
    qt_signals.hpp
)

# Link the executable with Qt6 Core, and the common library.
target_link_libraries(qt_signals_example PRIVATE Qt6::Core common)

# Add a post-build step to run windeployqt automatically on Windows.
if(WIN32)
    # Determine the path to windeployqt based on Qt6_DIR.
    # Qt6_DIR is something like "C:/Qt/6.8.2/msvc2022_64/lib/cmake/Qt6".
    # To get the corresponding bin directory "C:/Qt/6.8.2/msvc2022_64/bin",
    # we need to go up three directories.
    get_filename_component(_qt_bin_dir "${Qt6_DIR}/../../../bin" ABSOLUTE)
    message(STATUS "Qt bin directory computed as: ${_qt_bin_dir}")
    add_custom_command(TARGET qt_signals_example POST_BUILD
        COMMAND "${_qt_bin_dir}/windeployqt" "$<TARGET_FILE:qt_signals_example>"
        COMMENT "Running windeployqt for deployment..."
    )
endif()