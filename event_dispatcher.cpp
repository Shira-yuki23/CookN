#include "event_dispatcher.h"
#include <iostream>

void EventDispatcher::subscribe(const std::string& entity_id, EventCallback callback)
{
    subscribers[entity_id].push_back(callback);
}

void EventDispatcher::enqueue_event(std::unique_ptr<Event> event)
{
    std::lock_guard<std::mutex> lock(queue_mutex);
    event_queue.push(std::move(event));
}

void EventDispatcher::process_events()
{
    std::queue<std::unique_ptr<Event>> local_queue;

    // Move events into a local queue to minimize lock time
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        std::swap(local_queue, event_queue);
    }

    while (!local_queue.empty())
    {
        std::unique_ptr<Event> event = std::move(local_queue.front());
        local_queue.pop();

        // Broadcast to all subscribers if target_id is empty
        if (event->target_id.empty())
        {
            for (auto& [entity_id, callbacks] : subscribers)
            {
                for (auto& cb : callbacks)
                {
                    cb(*event);
                }
            }
        }
        else
        {
            auto it = subscribers.find(event->target_id);
            if (it != subscribers.end())
            {
                for (auto& cb : it->second)
                {
                    cb(*event);
                }
            }
        }
    }
}