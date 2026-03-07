 #pragma once
#include <vector>
#include <string>
#include <iostream>

// Base class for any event listener
class EventListener
{
public:
    virtual ~EventListener() = default;
    virtual void OnEvent(const std::string& eventName) = 0; // virtual function
};

// EventDispatcher handles notifying listeners
class EventDispatcher
{
private:
    std::vector<EventListener*> listeners;

public:
    EventDispatcher() = default;
    ~EventDispatcher() = default;

    void Register(EventListener* listener)
    {
        listeners.push_back(listener);
    }

    void Unregister(EventListener* listener)
    {
        listeners.erase(
            std::remove(listeners.begin(), listeners.end(), listener),
            listeners.end()
        );
    }

    void TriggerEvent(const std::string& eventName)
    {
        std::cout << "[EventDispatcher] Triggering event: " << eventName << std::endl;
        for (auto listener : listeners)
        {
            listener->OnEvent(eventName); // polymorphic call
        }
    }
};