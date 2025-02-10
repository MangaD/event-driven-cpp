/**
 * @file qt_signals_test.cpp
 * @brief Unit tests for the Qt signals and slots demonstration.
 *
 * This file contains tests to verify that the QtSignalsExample class correctly emits
 * signals and that these signals can be received by connected slots. The test creates an
 * instance of QtSignalsExample, connects its signal to a lambda function that records the
 * received message, and then emits a test signal. Assertions verify that the slot is called
 * and that the received message matches the expected value.
 *
 * To run this test, a QCoreApplication is instantiated to provide the necessary Qt event
 * loop, even though the direct connection should be immediate.
 */

#include <QCoreApplication>
#include <QString>
#include <cassert>
#include <iostream>
#include "qt_signals/qt_signals.hpp"

int main(int argc, char* argv[]) {
    // Create a QCoreApplication to provide the Qt event loop.
    QCoreApplication app(argc, argv);

    // Create an instance of QtSignalsExample.
    QtSignalsExample example;

    // Variables to capture the results from the signal-slot connection.
    bool slotCalled = false;
    QString receivedMessage;

    // Connect the 'mySignal' signal to a lambda that sets the flag and captures the message.
    bool connected = QObject::connect(&example, &QtSignalsExample::mySignal,
                                        [&slotCalled, &receivedMessage](const QString &msg) {
        slotCalled = true;
        receivedMessage = msg;
    });
    // Verify that the connection was successful.
    assert(connected && "Signal-slot connection failed");

    // Define the test message to be emitted.
    QString testMsg = "Test message";

    // Emit the signal with the test message.
    example.emitSignal(testMsg);

    // Assert that the slot was called.
    assert(slotCalled && "Slot was not called after signal emission");

    // Assert that the received message matches the test message.
    assert(receivedMessage == testMsg && "Received message does not match the emitted message");

    std::cout << "All Qt signals tests passed." << std::endl;
    return 0;
}
