/**
 * @file callbacks.cpp
 * @brief Implementation of the Event class for handling callbacks.
 *
 * This file implements the methods declared in callbacks.hpp which
 * allow setting and triggering a callback event.
 */

#include "callbacks.hpp"

namespace callbacks {

void Event::setCallback(Callback cb) {
    callback_ = cb;
}

void Event::trigger() {
    if (callback_) {
        callback_();
    }
}

} // namespace callbacks