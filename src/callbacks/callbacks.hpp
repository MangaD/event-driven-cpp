/**
 * @file callbacks.hpp
 * @brief Declaration of the Event class for handling callbacks.
 *
 * This file declares the Event class, which provides a simple mechanism for
 * setting and triggering callback events using std::function.
 */

#ifndef CALLBACKS_HPP
#define CALLBACKS_HPP

#include <functional>

/**
 * @brief A simple class for handling callback events.
 *
 * The Event class allows clients to register a callback function which will be
 * invoked when the event is triggered.
 */
class Event {
public:
    /**
     * @brief Type alias for a callback function.
     *
     * Represents a callable that takes no arguments and returns void.
     */
    using Callback = std::function<void()>;

    /**
     * @brief Sets the callback function.
     *
     * Assigns the callback function that will be invoked when trigger() is called.
     *
     * @param cb The callback function to set.
     */
    void setCallback(Callback cb);

    /**
     * @brief Triggers the event.
     *
     * Invokes the stored callback function if one has been set.
     */
    void trigger();

private:
    Callback callback_;  ///< The callback function to be triggered.
};

#endif // CALLBACKS_HPP
