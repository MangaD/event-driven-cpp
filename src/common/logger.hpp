/**
 * @file logger.hpp
 * @brief Declaration of the Logger class for logging messages.
 *
 * This file declares the Logger class within the common namespace. The Logger
 * class provides static methods for logging messages at various log levels.
 * Messages are output to the standard output stream (for Debug, Info, and Warning)
 * or to the standard error stream (for Error).
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace common {

/**
 * @brief Enumeration of log levels.
 */
enum class LogLevel {
    Debug,   ///< Debug log level.
    Info,    ///< Informational log level.
    Warning, ///< Warning log level.
    Error    ///< Error log level.
};

/**
 * @brief A simple logging utility.
 *
 * The Logger class provides static methods for logging messages at different log
 * levels. The current log level determines which messages are actually output.
 */
class Logger {
public:
    /**
     * @brief Sets the current log level.
     *
     * Only messages with a log level equal to or higher than the current log level
     * will be output.
     *
     * @param level The new log level to be set.
     */
    static void setLogLevel(LogLevel level);

    /**
     * @brief Logs a debug message.
     *
     * @param message The debug message to log.
     */
    static void debug(const std::string &message);

    /**
     * @brief Logs an informational message.
     *
     * @param message The informational message to log.
     */
    static void info(const std::string &message);

    /**
     * @brief Logs a warning message.
     *
     * @param message The warning message to log.
     */
    static void warning(const std::string &message);

    /**
     * @brief Logs an error message.
     *
     * @param message The error message to log.
     */
    static void error(const std::string &message);

private:
    /**
     * @brief Converts a LogLevel to its string representation.
     *
     * @param level The log level to convert.
     * @return A string representing the log level.
     */
    static std::string logLevelToString(LogLevel level);

    /**
     * @brief The current logging level.
     *
     * Only messages with a log level equal to or higher than this value will be logged.
     */
    static LogLevel currentLevel;
};

} // namespace common

#endif // LOGGER_HPP
