/**
 * @file main.cpp
 * @brief Demonstrates the usage of the Event class for handling callbacks.
 *
 * This example creates an Event instance, sets a callback using a lambda,
 * and triggers the event, which in turn calls the callback function.
 */

#include <iostream>
#include "callbacks.hpp"

using namespace callbacks;
 
int main() {
    // Create an Event instance.
    Event event;

    // Set the callback function using a lambda expression.
    event.setCallback([]() {
        std::cout << "Callback triggered: Hello from the Event!" << std::endl;
    });

    // Trigger the event, which invokes the callback.
    event.trigger();

    return 0;
}
 