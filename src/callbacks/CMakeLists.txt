cmake_minimum_required(VERSION 3.10)

project(callbacks_example)

# Set C++20 standard and enforce its use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include the common utilities header files if needed.
include_directories(${CMAKE_SOURCE_DIR}/src/common)

# Add the executable target composed of main.cpp and callbacks.cpp.
add_executable(callbacks_example
    main.cpp
    callbacks.cpp
)

# Link the executable with the common library if the callbacks example uses it.
target_link_libraries(callbacks_example common)
