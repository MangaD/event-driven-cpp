#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>

namespace common {

enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error
};

class Logger {
public:
    // Set the current logging level
    static void setLogLevel(LogLevel level);

    // Log a debug message
    static void debug(const std::string &message);

    // Log an info message
    static void info(const std::string &message);

    // Log a warning message
    static void warning(const std::string &message);

    // Log an error message
    static void error(const std::string &message);

private:
    // Returns a string representation of the log level
    static std::string logLevelToString(LogLevel level);

    // The current logging level; messages with a lower level will be ignored.
    // Default is Info.
    static LogLevel currentLevel;
};

} // namespace common

#endif // LOGGER_HPP
