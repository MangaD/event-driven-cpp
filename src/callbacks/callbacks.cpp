/**
 * @file callbacks.cpp
 * @brief Implementation of the Event class for handling callbacks.
 *
 * This file implements the methods declared in callbacks.hpp which
 * allow setting and triggering a callback event.
 */

#include "callbacks.hpp"

/**
 * @brief Sets the callback function to be invoked when the event is triggered.
 *
 * @param cb A std::function that takes no arguments and returns void.
 */
void Event::setCallback(Callback cb) {
    callback_ = cb;
}

/**
 * @brief Triggers the event by invoking the stored callback function.
 *
 * If a callback has been set using setCallback(), this method will call it.
 * Otherwise, it does nothing.
 */
void Event::trigger() {
    if (callback_) {
        callback_();
    }
}
