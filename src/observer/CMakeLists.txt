cmake_minimum_required(VERSION 3.10)

project(observer_example)

# Set C++20 standard and enforce its use.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include the common utilities header files if needed.
include_directories(${CMAKE_SOURCE_DIR}/src/common)

# Add the executable target composed of main.cpp and observer.cpp.
add_executable(observer_example
    main.cpp
)

# Link the executable with the common library (if the common library is built in the project).
# This assumes that the common library is defined with the target name "common".
target_link_libraries(observer_example common)