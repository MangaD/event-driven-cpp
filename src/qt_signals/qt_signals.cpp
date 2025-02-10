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

namespace qt_signals {

QtSignalsExample::QtSignalsExample(QObject *parent)
    : QObject(parent) {
}

void QtSignalsExample::emitSignal(const QString &message) {
    emit mySignal(message);
}

void QtSignalsExample::onMySignal(const QString &message) {
    qDebug() << "Received signal with message:" << message;
}

} // namespace qt_signals