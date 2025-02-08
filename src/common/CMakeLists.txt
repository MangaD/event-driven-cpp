# Specify the minimum CMake version required for this subproject.
cmake_minimum_required(VERSION 3.10)

# Create a library target named "common" using the source file(s) in this directory.
add_library(common
    logger.cpp
)

# Specify that the current directory (which contains logger.hpp) should be added
# to the include path for any target that links against the "common" library.
target_include_directories(common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
