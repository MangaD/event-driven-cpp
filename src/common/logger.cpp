/**
 * @file logger.cpp
 * @brief Implementation of the Logger class for logging messages.
 *
 * This file implements the Logger class declared in logger.hpp, which provides
 * simple logging functionality with various log levels.
 */

#include "logger.hpp"
#include <iostream>

namespace common {

/**
 * @brief The current log level threshold.
 *
 * Only messages with a log level equal to or higher than this value will be output.
 * The default log level is set to Info.
 */
LogLevel Logger::currentLevel = LogLevel::Info;

/**
 * @brief Sets the logging level.
 *
 * This function sets the current logging level. Messages with a log level lower
 * than the current level will be ignored.
 *
 * @param level The new logging level to be set.
 */
void Logger::setLogLevel(LogLevel level) {
    currentLevel = level;
}

/**
 * @brief Converts a log level to its corresponding string representation.
 *
 * @param level The log level to convert.
 * @return A string representing the log level.
 */
std::string Logger::logLevelToString(LogLevel level) {
    switch(level) {
        case LogLevel::Debug:   return "DEBUG";
        case LogLevel::Info:    return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error:   return "ERROR";
        default:                return "UNKNOWN";
    }
}

/**
 * @brief Logs a debug message.
 *
 * If the current log level is Debug or lower, this function outputs a debug message
 * to the standard output.
 *
 * @param message The message to be logged.
 */
void Logger::debug(const std::string &message) {
    if (static_cast<int>(LogLevel::Debug) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Debug) << "] " << message << std::endl;
    }
}

/**
 * @brief Logs an informational message.
 *
 * If the current log level is Info or lower, this function outputs an info message
 * to the standard output.
 *
 * @param message The message to be logged.
 */
void Logger::info(const std::string &message) {
    if (static_cast<int>(LogLevel::Info) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Info) << "] " << message << std::endl;
    }
}

/**
 * @brief Logs a warning message.
 *
 * If the current log level is Warning or lower, this function outputs a warning message
 * to the standard output.
 *
 * @param message The message to be logged.
 */
void Logger::warning(const std::string &message) {
    if (static_cast<int>(LogLevel::Warning) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Warning) << "] " << message << std::endl;
    }
}

/**
 * @brief Logs an error message.
 *
 * If the current log level is Error or lower, this function outputs an error message
 * to the standard error.
 *
 * @param message The message to be logged.
 */
void Logger::error(const std::string &message) {
    if (static_cast<int>(LogLevel::Error) >= static_cast<int>(currentLevel)) {
        std::cerr << "[" << logLevelToString(LogLevel::Error) << "] " << message << std::endl;
    }
}

} // namespace common
