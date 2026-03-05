 #pragma once
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

// Base class for all loggers
class Logger
{
public:
    virtual ~Logger() = default;

    // Polymorphic function
    virtual void log(const std::string& message) const = 0;

    virtual void error(const std::string& message) const
    {
        std::cerr << "[ERROR] " << message << std::endl;
    }
};

// Console logger
class ConsoleLogger : public Logger
{
public:
    void log(const std::string& message) const override
    {
        std::cout << "[LOG] " << message << std::endl;
    }
};

// File logger
class FileLogger : public Logger
{
private:
    std::string filename;
public:
    FileLogger(const std::string& file) : filename(file) {}

    void log(const std::string& message) const override
    {
        std::ofstream out(filename, std::ios::app);
        if (out.is_open())
        {
            out << "[LOG] " << message << std::endl;
        }
    }
};