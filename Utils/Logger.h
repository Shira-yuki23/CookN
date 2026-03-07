 #pragma once
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

// Log levels
enum class LogLevel
{
    INFO,
    WARNING,
    ERROR
};

// Base class for all loggers
class Logger
{
public:
    virtual ~Logger() = default;

    // Polymorphic logging
    virtual void log(const std::string& message, LogLevel level = LogLevel::INFO) const = 0;

protected:
    std::string levelToString(LogLevel level) const
    {
        switch(level)
        {
            case LogLevel::INFO: return "[INFO]";
            case LogLevel::WARNING: return "[WARNING]";
            case LogLevel::ERROR: return "[ERROR]";
        }
        return "[LOG]";
    }
};

// Console logger
class ConsoleLogger : public Logger
{
public:
    void log(const std::string& message, LogLevel level = LogLevel::INFO) const override
    {
        std::cout << levelToString(level) << " " << message << std::endl;
    }
};

// File logger
class FileLogger : public Logger
{
private:
    std::string filename;

public:
    FileLogger(const std::string& file) : filename(file) {}

    void log(const std::string& message, LogLevel level = LogLevel::INFO) const override
    {
        std::ofstream out(filename, std::ios::app);

        if(out.is_open())
        {
            out << levelToString(level) << " " << message << std::endl;
        }
    }
};