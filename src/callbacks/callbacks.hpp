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
 * @namespace callbacks
 * @brief Provides functionality for handling event callbacks.
 *
 * The callbacks namespace encapsulates a simple mechanism for event-driven programming using callbacks.
 * It defines classes and functions that allow a callback function to be registered and triggered at a later
 * point. The primary class in this namespace is the Event class, which uses a `std::function<void()>` to store
 * a callback. This design enables decoupling of the event producer from the event consumer.
 *
 * The Event class provides methods such as:
 * - `setCallback()`: to assign a callback function.
 * - `trigger()`: to invoke the assigned callback.
 *
 * This mechanism is useful for asynchronous event handling in scenarios where you want to notify parts of your
 * application when certain events occur without tightly coupling components.
 */
namespace callbacks {

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

} // namespace callbacks

#endif // CALLBACKS_HPP
