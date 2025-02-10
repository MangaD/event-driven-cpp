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
    if (static_cast<int>(LogLevel::Debug) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Debug) << "] " << message << std::endl;
    }
}

void Logger::info(const std::string &message) {
    if (static_cast<int>(LogLevel::Info) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Info) << "] " << message << std::endl;
    }
}

void Logger::warning(const std::string &message) {
    if (static_cast<int>(LogLevel::Warning) >= static_cast<int>(currentLevel)) {
        std::cout << "[" << logLevelToString(LogLevel::Warning) << "] " << message << std::endl;
    }
}

void Logger::error(const std::string &message) {
    if (static_cast<int>(LogLevel::Error) >= static_cast<int>(currentLevel)) {
        std::cerr << "[" << logLevelToString(LogLevel::Error) << "] " << message << std::endl;
    }
}

} // namespace common
