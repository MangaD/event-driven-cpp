cmake_minimum_required(VERSION 3.10)

# Set the project name.
project(io_and_sockets_example)

# Set the C++ standard to C++20 and enforce its use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include the common utilities directory (if shared utilities like logging are used).
include_directories(${CMAKE_SOURCE_DIR}/src/common)

# Add the executable target for the I/O and sockets demonstration.
# This target is built from io_and_sockets.cpp, which implements
# a demonstration that monitors both socket events and console I/O.
add_executable(io_and_sockets_example
    io_and_sockets.cpp
    main.cpp
)

# On Windows, link against the ws2_32 library which provides the Winsock API functions.
if(WIN32)
    target_link_libraries(io_and_sockets_example PRIVATE ws2_32)
endif()

target_link_libraries(io_and_sockets_example PRIVATE common)

# Optionally, print a status message showing the project configuration.
message(STATUS "Configured io_and_sockets_example with C++20 and common utilities from ${CMAKE_SOURCE_DIR}/src/common")
