/**
 * @file qt_signals.hpp
 * @brief Declaration of a simple Qt signals and slots example class.
 *
 * This file declares the QtSignalsExample class, which demonstrates the use of Qt's
 * signals and slots mechanism for event-driven programming. The class emits a signal
 * and provides a slot to handle the event.
 */

#ifndef QT_SIGNALS_HPP
#define QT_SIGNALS_HPP

#include <QObject>
#include <QString>

/**
 * @namespace qt_signals
 * @brief Demonstrates the usage of Qt's signals and slots mechanism.
 *
 * This namespace provides an example of how to use Qt's signals and slots mechanism to
 * implement event-driven programming in C++. The primary class within this namespace,
 * QtSignalsExample, illustrates how to declare signals and slots using the Q_OBJECT macro,
 * how to connect signals to slots, and how to emit signals to trigger corresponding actions.
 *
 * The example leverages the Qt Core module and its meta-object system for type-safe communication
 * between objects, enabling a decoupled and flexible design.
 */
namespace qt_signals {

/**
 * @brief A simple class demonstrating Qt's signals and slots.
 *
 * The QtSignalsExample class inherits from QObject and uses the Q_OBJECT macro
 * to enable the meta-object features of Qt, including signals and slots.
 */
class QtSignalsExample : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Constructs a new QtSignalsExample object.
     * @param parent Pointer to the parent QObject. Defaults to nullptr.
     */
    explicit QtSignalsExample(QObject *parent = nullptr);

    /**
     * @brief Emits the signal with the provided message.
     *
     * This method demonstrates how to emit a signal.
     *
     * @param message The QString message to be sent with the signal.
     */
    void emitSignal(const QString &message);

signals:
    /**
     * @brief Signal emitted with a message.
     *
     * This signal is emitted by the QtSignalsExample object to notify connected
     * slots with a QString message.
     *
     * @param message The message being sent.
     */
    void mySignal(const QString &message);

public slots:
    /**
     * @brief Slot that receives a message.
     *
     * This slot is connected to the mySignal signal and handles incoming messages.
     *
     * @param message The QString message received from the signal.
     */
    void onMySignal(const QString &message);
};

} // namespace qt_signals

#endif // QT_SIGNALS_HPP
