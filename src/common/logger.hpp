#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>

namespace common {

/**
 * @namespace common
 * @brief Contains common utilities and classes used across the project.
 */

/**
 * @brief Log levels for the Logger.
 */
enum class LogLevel {
    Debug,   ///< Debug level
    Info,    ///< Info level
    Warning, ///< Warning level
    Error    ///< Error level
};

/**
 * @brief A simple logger class to log messages with different severity levels.
 */
class Logger {
public:
    /**
     * @brief Set the current logging level.
     * 
     * @param level The logging level to set.
     */
    static void setLogLevel(LogLevel level);

    /**
     * @brief Log a debug message.
     * 
     * @param message The message to log.
     */
    static void debug(const std::string &message);

    /**
     * @brief Log an info message.
     * 
     * @param message The message to log.
     */
    static void info(const std::string &message);

    /**
     * @brief Log a warning message.
     * 
     * @param message The message to log.
     */
    static void warning(const std::string &message);

    /**
     * @brief Log an error message.
     * 
     * @param message The message to log.
     */
    static void error(const std::string &message);

private:
    /**
     * @brief Returns a string representation of the log level.
     * 
     * @param level The log level.
     * @return A string representation of the log level.
     */
    static std::string logLevelToString(LogLevel level);

    // The current logging level; messages with a lower level will be ignored.
    // Default is Info.
    static LogLevel currentLevel;
};

} // namespace common

#endif // LOGGER_HPP
