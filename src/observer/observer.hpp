#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string_view>

/**
 * @brief IObserver interface definition for the Observer pattern.
 * 
 * Classes that wish to be notified of events should inherit from this interface
 * and implement the onNotify method.
 */
class IObserver {
public:
    virtual ~IObserver() = default;

    /**
     * @brief Method called by the Subject to notify the observer of an event.
     * 
     * @param message The message parameter carries details about the event.
     */
    virtual void onNotify(std::string_view message) = 0;
};

#endif // OBSERVER_HPP
