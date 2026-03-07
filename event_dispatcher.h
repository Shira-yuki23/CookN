#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include "Event.h"
#include "entity_manager.h"

class EventDispatcher {
public:
    EventDispatcher() = default;
    ~EventDispatcher() = default;

    void dispatch(Event& event, EntityManager& manager);
};

#endif