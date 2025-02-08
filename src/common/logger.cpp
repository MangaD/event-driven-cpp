#include "logger.hpp"

namespace common {

/**
 * @brief The Logger class provides logging functionalities with different log levels.
 */
class Logger {
public:
    /**
     * @brief Sets the current log level.
     * @param level The log level to set.
     */
    static void setLogLevel(LogLevel level);

    /**
     * @brief Converts a log level to its string representation.
     * @param level The log level to convert.
     * @return The string representation of the log level.
     */
    static std::string logLevelToString(LogLevel level);

    /**
     * @brief Logs a debug message.
     * @param message The message to log.
     */
    static void debug(const std::string &message);

    /**
     * @brief Logs an info message.
     * @param message The message to log.
     */
    static void info(const std::string &message);

    /**
     * @brief Logs a warning message.
     * @param message The message to log.
     */
    static void warning(const std::string &message);

    /**
     * @brief Logs an error message.
     * @param message The message to log.
     */
    static void error(const std::string &message);

private:
    /**
     * @brief The current log level.
     */
    static LogLevel currentLevel;
};

// Define and initialize the static member for the current log level.
// Default log level is set to Info.
LogLevel Logger::currentLevel = LogLevel::Info;

void Logger::setLogLevel(LogLevel level) {
    currentLevel = level;
}

std::string Logger::logLevelToString(LogLevel level) {
    switch(level) {
        case LogLevel::Debug:   return "DEBUG";
        case LogLevel::Info:    return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error:   return "ERROR";
        default:                return "UNKNOWN";
    }
}

void Logger::debug(const std::string &message) {
    // Only log if Debug level is at or above the current logging level.
    if (static_cast<int>(LogLevel::Debug) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Debug) << "] " << message << std::endl;
    }
}

void Logger::info(const std::string &message) {
    // Only log if Info level is at or above the current logging level.
    if (static_cast<int>(LogLevel::Info) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Info) << "] " << message << std::endl;
    }
}

void Logger::warning(const std::string &message) {
    // Only log if Warning level is at or above the current logging level.
    if (static_cast<int>(LogLevel::Warning) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Warning) << "] " << message << std::endl;
    }
}

void Logger::error(const std::string &message) {
    // Only log if Error level is at or above the current logging level.
    if (static_cast<int>(LogLevel::Error) >= static_cast<int>(currentLevel)) {
        std::cerr << "[" << logLevelToString(LogLevel::Error) << "] " << message << std::endl;
    }
}

} // namespace common
