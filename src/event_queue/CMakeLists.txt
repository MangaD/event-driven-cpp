cmake_minimum_required(VERSION 3.10)

# Define the project name for the Event Queue example.
project(event_queue_example)

# Set C++20 standard and enforce its use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include the common utilities directory (if the event queue example uses shared utilities like logging).
include_directories(${CMAKE_SOURCE_DIR}/src/common)

# Add the executable target for the Event Queue example.
# This target builds the event queue demonstration from main.cpp, event_queue.cpp, and includes event_queue.hpp.
add_executable(event_queue_example
    main.cpp
    event_queue.cpp
    event_queue.hpp
)

# Link the executable with the common library (if your event queue example depends on shared utilities).
target_link_libraries(event_queue_example PRIVATE common)

# Optional: Print a status message to confirm configuration.
message(STATUS "Configured event_queue_example with C++20 and common utilities from ${CMAKE_SOURCE_DIR}/src/common")
