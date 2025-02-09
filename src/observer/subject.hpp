/**
 * @file subject.hpp
 * @brief Declaration of the Subject class for the Observer pattern.
 *
 * This file declares the Subject class, which maintains a list of observers and
 * notifies them about events. Observers can be added or removed dynamically.
 */

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "observer.hpp"
#include <vector>
#include <algorithm>
#include <string>

/**
 * @brief The Subject class manages a list of observers and notifies them of events.
 *
 * The Subject class provides methods to add and remove observers, as well as to notify
 * all registered observers by calling their onNotify() method.
 */
class Subject {
public:
    /**
     * @brief Adds an observer to the list of observers.
     *
     * @param observer A pointer to an object implementing the IObserver interface.
     */
    void addObserver(IObserver* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Removes an observer from the list.
     *
     * @param observer A pointer to the observer to remove.
     */
    void removeObserver(IObserver* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    /**
     * @brief Notifies all registered observers of an event.
     *
     * This method calls the onNotify() function on each observer, passing the provided
     * message.
     *
     * @param message A string describing the event.
     */
    void notify(const std::string &message) {
        for (auto* observer : observers) {
            if (observer) {
                observer->onNotify(message);
            }
        }
    }

private:
    std::vector<IObserver*> observers; ///< Container storing pointers to the registered observers.
};

#endif // SUBJECT_HPP
