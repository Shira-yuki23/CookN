#include "event_dispatcher.h"

void EventDispatcher::dispatch(Event& event, EntityManager& manager)
{
    manager.broadcastEvent(event);
}