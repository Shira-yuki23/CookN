#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include "Event.h"
#include "Entity.h"
#include <functional>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>

class EventDispatcher {
public:
    using EventCallback = std::function<void(const Event&)>;

private:
    std::unordered_map<std::string, std::vector<EventCallback>> subscribers;
    std::queue<std::unique_ptr<Event>> event_queue;

public:
    EventDispatcher() = default;

    void subscribe(const std::string& entity_id, EventCallback callback);

    void enqueue_event(std::unique_ptr<Event> event);
    
    void process_events();
};

#endif