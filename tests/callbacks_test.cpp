/**
 * @file callbacks_test.cpp
 * @brief Unit tests for the callbacks example.
 *
 * This file contains unit tests for the Event class declared in callbacks.hpp.
 * The tests verify that:
 * - Triggering an event with no callback set causes no issues.
 * - A callback can be correctly set and invoked when the event is triggered.
 * - Setting a new callback replaces the previous one.
 *
 * Basic assertions are used to validate functionality.
 */

#include <cassert>
#include <iostream>
#include "callbacks/callbacks.hpp"

int main() {
    // Test 1: Triggering an event with no callback should not cause any errors.
    {
        Event event;
        // No callback is set; calling trigger() should be safe.
        event.trigger();
    }

    // Test 2: Verify that the callback is invoked.
    {
        Event event;
        bool callbackCalled = false;

        // Set a callback that updates the flag.
        event.setCallback([&callbackCalled]() {
            callbackCalled = true;
        });

        // Trigger the event.
        event.trigger();

        // Assert that the callback was invoked.
        assert(callbackCalled && "Callback should have been called after triggering the event.");
    }

    // Test 3: Verify that setting a new callback replaces the previous one.
    {
        Event event;
        int counter = 0;

        // Set an initial callback that increments counter by 1.
        event.setCallback([&counter]() {
            counter += 1;
        });
        event.trigger();
        assert(counter == 1 && "Counter should be 1 after first trigger.");

        // Replace the callback with one that increments counter by 2.
        event.setCallback([&counter]() {
            counter += 2;
        });
        event.trigger();
        assert(counter == 3 && "Counter should be 3 after replacing the callback and triggering.");
    }

    std::cout << "All callbacks tests passed." << std::endl;
    return 0;
}
