/**
 * @file qt_signals.cpp
 * @brief Implementation of the QtSignalsExample class.
 *
 * This file implements the QtSignalsExample class which demonstrates the usage
 * of Qt's signals and slots mechanism for event-driven programming. It includes
 * methods to emit a signal and a slot to handle the signal.
 */

#include "qt_signals.hpp"
#include <QDebug>

/**
 * @brief Constructs a new QtSignalsExample object.
 *
 * @param parent Pointer to the parent QObject. Defaults to nullptr.
 */
QtSignalsExample::QtSignalsExample(QObject *parent)
    : QObject(parent) {
}

/**
 * @brief Emits the mySignal signal with the provided message.
 *
 * This function demonstrates how to emit a Qt signal.
 *
 * @param message The QString message to be sent with the signal.
 */
void QtSignalsExample::emitSignal(const QString &message) {
    emit mySignal(message);
}

/**
 * @brief Slot that receives and handles the mySignal signal.
 *
 * This slot is connected to the mySignal signal and processes incoming messages.
 *
 * @param message The QString message received from the signal.
 */
void QtSignalsExample::onMySignal(const QString &message) {
    qDebug() << "Received signal with message:" << message;
}
 