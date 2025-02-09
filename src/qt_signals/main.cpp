/**
 * @file main.cpp
 * @brief Demonstrates the usage of Qt's signals and slots mechanism.
 *
 * This example creates an instance of the QtSignalsExample class, connects its signal
 * to its slot, and emits a signal to showcase how messages are transmitted using Qt's
 * event-driven system.
 */

#include <QCoreApplication>
#include "qt_signals.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create an instance of QtSignalsExample.
    QtSignalsExample example;

    // Connect the mySignal signal to the onMySignal slot.
    QObject::connect(&example, &QtSignalsExample::mySignal, &example, &QtSignalsExample::onMySignal);

    // Emit the signal with a test message.
    example.emitSignal("Hello from Qt Signals & Slots!");

    // Execute the Qt event loop.
    return app.exec();
}
