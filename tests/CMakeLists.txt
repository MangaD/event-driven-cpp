cmake_minimum_required(VERSION 3.10)

# Note: enable_testing() is already called in the root CMakeLists.txt,
# so we do not call it again here.

# Add the source directory to the include path so that tests can locate headers.
include_directories(${CMAKE_SOURCE_DIR}/src)

# -----------------------------------------------------------------------------
# Observer Pattern Test
# -----------------------------------------------------------------------------
add_executable(observer_test observer_test.cpp)
target_link_libraries(observer_test PRIVATE common)
add_test(NAME ObserverTest COMMAND observer_test)

# -----------------------------------------------------------------------------
# Callbacks Test
# -----------------------------------------------------------------------------
add_executable(callbacks_test
    callbacks_test.cpp
    ${CMAKE_SOURCE_DIR}/src/callbacks/callbacks.cpp
)
target_link_libraries(callbacks_test PRIVATE common)
add_test(NAME CallbacksTest COMMAND callbacks_test)

# -----------------------------------------------------------------------------
# Qt Signals & Slots Test
# -----------------------------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS Core)
add_executable(qt_signals_test 
    qt_signals_test.cpp
    ${CMAKE_SOURCE_DIR}/src/qt_signals/qt_signals.cpp
)
# Enable automatic MOC processing for Qt headers.
set_target_properties(qt_signals_test PROPERTIES AUTOMOC ON)
target_link_libraries(qt_signals_test PRIVATE Qt6::Core common)
if(WIN32)
    # Compute the Qt bin directory from Qt6_DIR (assumes Qt6_DIR is set, e.g. in CMakePresets)
    get_filename_component(_qt_bin_dir "${Qt6_DIR}/../../../bin" ABSOLUTE)
    message(STATUS "Qt bin directory for tests computed as: ${_qt_bin_dir}")
    # Add a post-build step to run windeployqt automatically on Windows.
    add_custom_command(TARGET qt_signals_test POST_BUILD
        COMMAND "${_qt_bin_dir}/windeployqt" "$<TARGET_FILE:qt_signals_test>"
        COMMENT "Running windeployqt for qt_signals_test deployment..."
    )
endif()
add_test(NAME QtSignalsTest COMMAND qt_signals_test)

# -----------------------------------------------------------------------------
# I/O and Sockets Test
# -----------------------------------------------------------------------------
add_executable(io_and_sockets_test
    io_and_sockets_test.cpp
    ${CMAKE_SOURCE_DIR}/src/io_and_sockets/io_and_sockets.cpp
)
if(WIN32)
    # Enable test mode so that runDemo() uses std::getline() on Windows.
    target_compile_definitions(io_and_sockets_test PUBLIC TEST_MODE)
    target_link_libraries(io_and_sockets_test PRIVATE ws2_32)
endif()
target_link_libraries(io_and_sockets_test PRIVATE common)
add_test(NAME IOAndSocketsTest COMMAND io_and_sockets_test)

# -----------------------------------------------------------------------------
# Event Queue Test
# -----------------------------------------------------------------------------
add_executable(event_queue_test
    event_queue_test.cpp
    ${CMAKE_SOURCE_DIR}/src/event_queue/event_queue.cpp
)
target_link_libraries(event_queue_test PRIVATE common)
add_test(NAME EventQueueTest COMMAND event_queue_test)
