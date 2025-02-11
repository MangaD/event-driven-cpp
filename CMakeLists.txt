cmake_minimum_required(VERSION 3.10)

option(BUILD_SOURCE "Build primary libraries and executables." ON)

set(PROJECT_LANGUAGES NONE)
if(${BUILD_SOURCE})
	  set(PROJECT_LANGUAGES CXX)
endif()

# Define the project
project(event_driven_cpp
    VERSION 1.0
    DESCRIPTION "A case study on event-driven programming in C++"
    LANGUAGES ${PROJECT_LANGUAGES}
)

# Set C++ standard to C++20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Optionally set the default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug, Release, etc.)" FORCE)
endif()

# Include the common directory for shared utilities (if used)
include_directories(${CMAKE_SOURCE_DIR}/src/common)

if(${BUILD_SOURCE})
    # Add subdirectories for each event mechanism example
    add_subdirectory(src/common)
    add_subdirectory(src/observer)
    add_subdirectory(src/callbacks)
    add_subdirectory(src/qt_signals)
    add_subdirectory(src/io_and_sockets)
    add_subdirectory(src/event_queue)

    # Enable testing and include tests if available
    enable_testing()
    add_subdirectory(tests)
endif()

# Optionally generate Doxygen documentation
find_package(Doxygen)
include(cmake/doxygen.cmake)