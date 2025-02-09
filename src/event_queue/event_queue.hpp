#ifndef EVENT_QUEUE_HPP
#define EVENT_QUEUE_HPP

/**
 * @file event_queue.hpp
 * @brief Declaration of the EventQueue class.
 *
 * This file declares the EventQueue class, which provides a thread-safe mechanism
 * for queuing and processing events. An event is represented as a callable object (using
 * std::function<void()>), allowing the decoupling of event production from event handling.
 * This is useful in event-driven architectures, game loops, or any asynchronous application.
 */

#include <queue>
#include <functional>
#include <mutex>

/**
 * @brief A thread-safe event queue.
 *
 * The EventQueue class allows you to enqueue events (callable objects) and later process
 * them sequentially (in a FIFO manner). It uses a mutex to ensure that operations on the queue
 * are safe across multiple threads.
 */
class EventQueue {
public:
    /**
     * @brief Type alias for an event.
     *
     * An event is defined as a callable object that takes no arguments and returns void.
     */
    using Event = std::function<void()>;

    /**
     * @brief Enqueues an event.
     *
     * Adds an event to the queue. The event will be executed when processEvents() is called.
     *
     * @param event The event to enqueue.
     */
    void pushEvent(const Event &event);

    /**
     * @brief Processes all events in the queue.
     *
     * Executes all events in the queue in FIFO order. After processing, the queue is empty.
     * This operation is thread-safe.
     */
    void processEvents();

    /**
     * @brief Checks whether the event queue is empty.
     *
     * @return true if the event queue contains no events, false otherwise.
     */
    bool isEmpty() const;

private:
    std::queue<Event> events_;  ///< The underlying queue storing events.
    mutable std::mutex mutex_;  ///< Mutex to protect access to the event queue.
};

#endif // EVENT_QUEUE_HPP
