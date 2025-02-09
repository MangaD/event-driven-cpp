/**
 * @file main.cpp
 * @brief Demonstrates the Observer pattern in C++.
 *
 * This example creates a Subject, registers concrete observers, and sends
 * notifications to them. It shows how the Subject can notify multiple observers
 * about events, and how observers can be dynamically added and removed.
 */

#include <iostream>
#include "subject.hpp"
#include "observer.hpp"

/**
 * @brief A concrete implementation of the IObserver interface.
 *
 * The ConcreteObserver class implements the onNotify() method to handle event
 * notifications by printing the received message to the standard output.
 */
class ConcreteObserver : public IObserver {
public:
    /**
     * @brief Handles the notification from the Subject.
     *
     * @param message A string containing details about the event.
     */
    void onNotify(const std::string &message) override {
        std::cout << "ConcreteObserver received: " << message << std::endl;
    }
};

int main() {
    // Create a Subject instance.
    Subject subject;

    // Create two ConcreteObserver instances.
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    // Register observers with the subject.
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Notify all observers with an event.
    std::cout << "Notifying observers (first time):" << std::endl;
    subject.notify("Event 1: Something happened!");

    // Remove one observer.
    subject.removeObserver(&observer1);

    // Notify the remaining observers.
    std::cout << "Notifying observers (second time):" << std::endl;
    subject.notify("Event 2: Observer 1 removed!");

    return 0;
}
