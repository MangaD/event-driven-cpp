/**
 * @file observer.hpp
 * @brief Declaration of the IObserver interface for the Observer pattern.
 *
 * This file declares the IObserver interface which defines the contract that
 * all observers must implement in order to receive event notifications from a Subject.
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

/**
 * @namespace observer
 * @brief Implements the Observer design pattern for event notifications.
 *
 * This namespace provides the fundamental components for implementing the Observer design pattern.
 * It defines the IObserver interface, which declares the callback method that must be implemented
 * by any class that wishes to receive event notifications, and the Subject class, which maintains
 * a list of observers and dispatches events to them.
 *
 * The Observer pattern facilitates a decoupled design where the subject does not need to know the
 * specifics of its observers. This results in a more modular and maintainable system, especially
 * in event-driven applications where multiple components need to respond to changes or events.
 */
namespace observer {

/**
 * @brief Interface for observer objects.
 *
 * The IObserver interface declares the onNotify() method that must be implemented
 * by any class that wishes to be notified of events by a Subject.
 */
class IObserver {
public:
    /**
     * @brief Virtual destructor.
     *
     * Ensures that derived classes are properly destroyed.
     */
    virtual ~IObserver() = default;

    /**
     * @brief Notifies the observer of an event.
     *
     * This pure virtual function must be overridden by derived classes to handle
     * event notifications.
     *
     * @param message A string containing details about the event.
     */
    virtual void onNotify(const std::string &message) = 0;
};

} // namespace observer

#endif // OBSERVER_HPP
