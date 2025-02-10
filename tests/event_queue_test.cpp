/**
 * @file event_queue_test.cpp
 * @brief Unit tests for the EventQueue class.
 *
 * This file contains unit tests for the EventQueue class to verify that:
 * - A newly created event queue is empty.
 * - Events are processed in FIFO order.
 * - Side effects from events occur as expected.
 * - The EventQueue is thread-safe by simulating concurrent event enqueuing.
 *
 * If any assertion fails, the test will abort, indicating an issue with the EventQueue implementation.
 */

#include "event_queue/event_queue.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace event_queue;

int main() {
    // Test 1: Verify that a newly created event queue is empty.
    {
        EventQueue eq;
        assert(eq.isEmpty() && "New event queue should be empty.");
    }
    
    // Test 2: Enqueue and process events; verify order and side effects.
    {
        EventQueue eq;
        int counter = 0;
        std::vector<int> order;

        // Push an event that increments counter by 1.
        eq.pushEvent([&counter, &order]() {
            counter += 1;
            order.push_back(counter); // Expected value: 1.
        });
        // Push an event that increments counter by 2.
        eq.pushEvent([&counter, &order]() {
            counter += 2;
            order.push_back(counter); // Expected value: 3.
        });
        // Push an event that multiplies counter by 3.
        eq.pushEvent([&counter, &order]() {
            counter *= 3;
            order.push_back(counter); // Expected value: 9.
        });
        
        // Process all enqueued events.
        eq.processEvents();
        
        // Verify that the queue is empty after processing.
        assert(eq.isEmpty() && "Event queue should be empty after processing events.");
        
        // Check that the counter has the expected final value:
        // 0 + 1 = 1, then 1 + 2 = 3, then 3 * 3 = 9.
        assert(counter == 9 && "Counter should be 9 after processing events.");
        
        // Verify that the events occurred in the correct order.
        assert(order.size() == 3 && "There should be 3 recorded events.");
        assert(order[0] == 1 && order[1] == 3 && order[2] == 9 && "Events did not occur in the expected order.");
    }
    
    // Test 3: Simulate concurrent event enqueuing.
    {
        EventQueue eq;
        int counter = 0;
        const int numThreads = 5;
        const int eventsPerThread = 10;
        
        std::vector<std::thread> threads;
        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back([&eq, &counter, eventsPerThread]() {
                for (int j = 0; j < eventsPerThread; ++j) {
                    // Enqueue an event that increments the counter.
                    eq.pushEvent([&counter]() {
                        ++counter;
                    });
                    // Sleep briefly to simulate work and allow interleaving.
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
            });
        }
        for (auto &t : threads) {
            t.join();
        }
        
        // Process all events after threads have finished enqueuing.
        eq.processEvents();
        
        // The counter should equal the total number of events enqueued.
        assert(counter == numThreads * eventsPerThread && "Counter should equal the total number of processed events.");
    }
    
    std::cout << "All event queue tests passed." << std::endl;
    return 0;
}
