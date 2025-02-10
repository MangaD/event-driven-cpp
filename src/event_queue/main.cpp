/**
 * @file main.cpp
 * @brief Entry point for the Event Queue demonstration.
 *
 * This example demonstrates how to use the EventQueue class to decouple event production
 * from event consumption in a thread-safe manner. Several events are enqueued as lambda
 * functions that print messages to the console. After enqueuing the events, the program
 * processes them in FIFO order.
 *
 * In real-world applications, events may be enqueued from multiple threads and processed
 * by a dedicated event loop. For simplicity, this demonstration enqueues and processes events
 * in the main thread.
 *
 * @note The EventQueue class is thread-safe, so it can safely be used in multi-threaded contexts.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include "event_queue.hpp"

using namespace event_queue;

int main() {
    // Create an instance of the EventQueue.
    EventQueue eq;

    // Enqueue several events.
    eq.pushEvent([](){
        std::cout << "Event 1: Hello, world!" << std::endl;
    });

    eq.pushEvent([](){
        std::cout << "Event 2: Processing the event queue." << std::endl;
    });

    eq.pushEvent([](){
        std::cout << "Event 3: Demonstrating event-driven programming in C++." << std::endl;
    });

    // Simulate asynchronous event production.
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    eq.pushEvent([](){
        std::cout << "Event 4: Added after a delay." << std::endl;
    });

    // Print a message indicating that events are about to be processed.
    std::cout << "Processing events..." << std::endl;

    // Process all events in the queue in FIFO order.
    eq.processEvents();

    // Verify that the event queue is now empty.
    if (eq.isEmpty()) {
        std::cout << "All events have been processed. The event queue is now empty." << std::endl;
    } else {
        std::cout << "There are still events remaining in the queue." << std::endl;
    }

    return 0;
}
 