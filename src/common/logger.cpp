#include "logger.hpp"

namespace common {

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
