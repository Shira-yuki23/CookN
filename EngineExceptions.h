#ifndef ENGINE_EXCEPTIONS_H
#define ENGINE_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class EngineException : public std::runtime_error
{
public:
    explicit EngineException(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

class InitializationException : public EngineException
{
public:
    explicit InitializationException(const std::string& message)
        : EngineException("Initialization Error: " + message)
    {
    }
};

class RendererException : public EngineException
{
public:
    explicit RendererException(const std::string& message)
        : EngineException("Renderer Error: " + message)
    {
    }
};

class SceneException : public EngineException
{
public:
    explicit SceneException(const std::string& message)
        : EngineException("Scene Error: " + message)
    {
    }
};

#endif
