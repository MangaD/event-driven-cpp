/**
 * @file main.cpp
 * @brief Demonstrates the observer pattern with a simple example.
 */

#include <iostream>
#include "observer.hpp"
#include "subject.hpp"

/**
 * @class ConcreteObserver
 * @brief A concrete implementation of the IObserver interface.
 */
class ConcreteObserver : public IObserver {
public:
    /**
     * @brief Called when the subject sends a notification.
     * @param message The message sent by the subject.
     */
    void onNotify(std::string_view message) override {
        std::cout << "ConcreteObserver received: " << message << std::endl;
    }
};

/**
 * @brief The main function demonstrating the observer pattern.
 * @return int Exit status.
 */
int main() {
    // Create a subject that will send notifications.
    Subject subject;

    // Create two concrete observers.
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    // Register observers with the subject.
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Notify all observers.
    std::cout << "Notifying observers the first time:" << std::endl;
    subject.notify("Event 1: Something happened!");

    // Remove one observer.
    subject.removeObserver(&observer1);

    // Notify the remaining observers.
    std::cout << "Notifying observers the second time:" << std::endl;
    subject.notify("Event 2: Observer 1 removed.");

    return 0;
}
