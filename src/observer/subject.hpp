#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "observer.hpp"
#include <vector>
#include <algorithm>
#include <string_view>

/**
 * @class Subject
 * @brief Manages a list of observers and notifies them of events.
 */
class Subject {
public:
    /**
     * @brief Adds an observer to the list.
     * @param observer Pointer to the observer to be added.
     */
    void addObserver(IObserver* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Removes an observer from the list.
     * @param observer Pointer to the observer to be removed.
     */
    void removeObserver(IObserver* observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    /**
     * @brief Notifies all registered observers by invoking their onNotify() method.
     * @param message The message to be sent to the observers.
     */
    void notify(std::string_view message) {
        for (auto* observer : observers) {
            if (observer) {
                observer->onNotify(message);
            }
        }
    }

private:
    /**
     * @brief Container storing pointers to the observers.
     */
    std::vector<IObserver*> observers;
};

#endif // SUBJECT_HPP
