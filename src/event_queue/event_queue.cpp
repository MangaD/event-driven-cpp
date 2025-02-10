/**
 * @file event_queue.cpp
 * @brief Implementation of the EventQueue class.
 *
 * This file implements the methods declared in event_queue.hpp. The EventQueue
 * class provides a thread-safe FIFO queue for storing and processing events,
 * where each event is represented as a callable object (std::function<void()>).
 * The implementation ensures that events can be pushed and processed safely across
 * multiple threads.
 */

#include "event_queue.hpp"

#include <utility>

namespace event_queue {

void EventQueue::pushEvent(const Event &event) {
    // Lock the mutex to ensure exclusive access to the queue.
    std::lock_guard<std::mutex> lock(mutex_);
    events_.push(event);
}

void EventQueue::processEvents() {
    while (true) {
        Event event;
        {
            // Lock the mutex to safely check and modify the queue.
            std::lock_guard<std::mutex> lock(mutex_);
            if (events_.empty()) {
                break; // Exit the loop if no events remain.
            }
            // Retrieve the event at the front of the queue.
            event = events_.front();
            events_.pop();
        }
        // Execute the event outside of the mutex lock to avoid holding the lock during execution.
        if (event) {
            event();
        }
    }
}

bool EventQueue::isEmpty() const {
    // Lock the mutex to safely access the queue.
    std::lock_guard<std::mutex> lock(mutex_);
    return events_.empty();
}

} // namespace event_queue