/**
 * @file observer_test.cpp
 * @brief Unit tests for the Observer pattern implementation.
 *
 * This file contains tests for verifying the functionality of the Observer pattern
 * implementation. The tests check that:
 * - Observers are notified when the subject sends an event.
 * - Multiple observers receive the notification.
 * - Removing an observer prevents it from receiving subsequent notifications.
 *
 * If any assertion fails, the test will abort, indicating an issue with the implementation.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "observer/observer.hpp"
#include "observer/subject.hpp"

using namespace observer;

/**
 * @brief A test observer that records notification messages.
 *
 * This class implements the IObserver interface and stores any messages it receives
 * in a vector. It is used to verify that notifications are delivered correctly.
 */
class TestObserver : public IObserver {
public:
    /**
     * @brief Callback method invoked when the subject notifies the observer.
     *
     * The received message is appended to an internal vector for later verification.
     *
     * @param message The message provided by the subject.
     */
    void onNotify(const std::string &message) override {
        messages.push_back(message);
    }

    /**
     * @brief Retrieves the messages received by this observer.
     *
     * @return A constant reference to the vector of received messages.
     */
    const std::vector<std::string>& getMessages() const {
        return messages;
    }

private:
    std::vector<std::string> messages; ///< Container to store received notification messages.
};

int main() {
    // Create a Subject instance.
    Subject subject;

    // Create two TestObserver instances.
    TestObserver observer1;
    TestObserver observer2;

    // Register both observers with the subject.
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Define a test message and notify all observers.
    std::string testMessage = "Test Event";
    subject.notify(testMessage);

    // Retrieve the messages from each observer.
    const auto& msgs1 = observer1.getMessages();
    const auto& msgs2 = observer2.getMessages();

    // Verify that both observers received exactly one message and it matches testMessage.
    assert(msgs1.size() == 1 && "Observer1 should have received exactly one message.");
    assert(msgs2.size() == 1 && "Observer2 should have received exactly one message.");
    assert(msgs1[0] == testMessage && "Observer1's message should match the test event.");
    assert(msgs2[0] == testMessage && "Observer2's message should match the test event.");

    // Remove observer1 from the subject.
    subject.removeObserver(&observer1);

    // Notify observers with a new message.
    std::string newMessage = "Another Test Event";
    subject.notify(newMessage);

    // After removal, observer1 should not receive the new message, while observer2 should.
    assert(observer1.getMessages().size() == 1 && "Observer1 should not have received the new message after removal.");
    assert(observer2.getMessages().size() == 2 && "Observer2 should have received two messages.");
    assert(observer2.getMessages()[1] == newMessage && "Observer2's second message should match the new test event.");

    std::cout << "All observer tests passed." << std::endl;
    return 0;
}
