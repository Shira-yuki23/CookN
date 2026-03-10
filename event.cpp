#include "Event.h"
#include <iostream>
#include <map>
#include <memory>

// Convert EventType to string for debugging
std::string event_type_to_string(EventType type) {

    static const std::map<EventType, std::string> type_map = {

        {EventType::NONE, "NONE"},

        {EventType::MOVE_UP, "MOVE_UP"},
        {EventType::MOVE_DOWN, "MOVE_DOWN"},
        {EventType::MOVE_LEFT, "MOVE_LEFT"},
        {EventType::MOVE_RIGHT, "MOVE_RIGHT"},

        {EventType::MOVE_UP_RELEASE, "MOVE_UP_RELEASE"},
        {EventType::MOVE_DOWN_RELEASE, "MOVE_DOWN_RELEASE"},
        {EventType::MOVE_LEFT_RELEASE, "MOVE_LEFT_RELEASE"},
        {EventType::MOVE_RIGHT_RELEASE, "MOVE_RIGHT_RELEASE"},

        {EventType::ATTACK, "ATTACK"},
        {EventType::INTERACT, "INTERACT"},
        {EventType::PAUSE, "PAUSE"},
        {EventType::QUIT, "QUIT"},

        {EventType::COLLISION, "COLLISION"},
        {EventType::BLOCKED, "BLOCKED"},
        {EventType::ITEM_COLLECTED, "ITEM_COLLECTED"},

        {EventType::DAMAGE_TAKEN, "DAMAGE_TAKEN"},
        {EventType::HEAL, "HEAL"},
        {EventType::DEATH, "DEATH"},

        {EventType::SCENE_SWITCH, "SCENE_SWITCH"},
        {EventType::LEVEL_COMPLETE, "LEVEL_COMPLETE"},
        {EventType::GAME_OVER, "GAME_OVER"},

        {EventType::SPAWN, "SPAWN"},
        {EventType::DESTROY, "DESTROY"}
    };

    auto it = type_map.find(type);

    if (it != type_map.end())
        return it->second;

    return "UNKNOWN";
}


// Overload << operator for Event
std::ostream& operator<<(std::ostream& os, const Event& e) {

    os << "Event[type=" << event_type_to_string(e.type)
       << ", sender=" << (e.sender_id.empty() ? "none" : e.sender_id)
       << ", target=" << (e.target_id.empty() ? "broadcast" : e.target_id)
       << ", value=" << e.value
       << ", age=" << e.get_age_in_seconds() << "s]";

    return os;
}


// Overload << for InputEvent
std::ostream& operator<<(std::ostream& os, const InputEvent& e) {

    os << "InputEvent[type=" << event_type_to_string(e.type)
       << ", sender=" << (e.sender_id.empty() ? "none" : e.sender_id)
       << ", key=" << e.key_code
       << ", held=" << (e.is_held ? "yes" : "no") << "]";

    return os;
}


// Overload << for CollisionEvent
std::ostream& operator<<(std::ostream& os, const CollisionEvent& e) {

    os << "CollisionEvent[sender=" << e.sender_id
       << ", other=" << e.other_entity_id
       << ", pos=(" << e.collision_x << "," << e.collision_y << ")]";

    return os;
}


// Overload << for CombatEvent
std::ostream& operator<<(std::ostream& os, const CombatEvent& e) {

    os << "CombatEvent[type=" << event_type_to_string(e.type)
       << ", attacker=" << e.attacker_id
       << ", defender=" << e.defender_id
       << ", damage=" << e.damage_amount << "]";

    return os;
}


// Overload << for SceneEvent
std::ostream& operator<<(std::ostream& os, const SceneEvent& e) {

    os << "SceneEvent[type=" << event_type_to_string(e.type)
       << ", sender=" << e.sender_id
       << ", scene=" << e.scene_name
       << ", previous=" << (e.previous_scene.empty() ? "none" : e.previous_scene)
       << "]";

    return os;
}


// Overload << for EntityLifecycleEvent
std::ostream& operator<<(std::ostream& os, const EntityLifecycleEvent& e) {

    os << "EntityLifecycleEvent[type=" << event_type_to_string(e.type)
       << ", entity=" << e.sender_id
       << ", entity_type=" << e.entity_type;

    if (e.type == EventType::SPAWN) {
        os << ", spawn_pos=(" << e.spawn_x << "," << e.spawn_y << ")";
    }

    os << "]";

    return os;
}


// Clone event helper
std::unique_ptr<Event> clone_event(const Event& event) {

    if (const InputEvent* e = dynamic_cast<const InputEvent*>(&event)) {

        return std::make_unique<InputEvent>(
            e->type,
            e->sender_id,
            e->key_code,
            e->is_held
        );
    }

    else if (const CollisionEvent* e = dynamic_cast<const CollisionEvent*>(&event)) {

        return std::make_unique<CollisionEvent>(
            e->sender_id,
            e->other_entity_id,
            e->collision_x,
            e->collision_y
        );
    }

    else if (const CombatEvent* e = dynamic_cast<const CombatEvent*>(&event)) {

        if (e->type == EventType::HEAL) {

            return std::make_unique<CombatEvent>(
                CombatEvent::create_heal(
                    e->attacker_id,
                    e->defender_id,
                    e->damage_amount
                )
            );
        }

        return std::make_unique<CombatEvent>(
            e->attacker_id,
            e->defender_id,
            e->damage_amount
        );
    }

    else if (const SceneEvent* e = dynamic_cast<const SceneEvent*>(&event)) {

        return std::make_unique<SceneEvent>(
            e->type,
            e->sender_id,
            e->scene_name,
            e->previous_scene
        );
    }

    else if (const EntityLifecycleEvent* e = dynamic_cast<const EntityLifecycleEvent*>(&event)) {

        if (e->type == EventType::SPAWN) {

            return std::make_unique<EntityLifecycleEvent>(
                EntityLifecycleEvent::create_spawn(
                    e->sender_id,
                    e->entity_type,
                    e->spawn_x,
                    e->spawn_y
                )
            );
        }

        return std::make_unique<EntityLifecycleEvent>(
            EntityLifecycleEvent::create_destroy(e->sender_id)
        );
    }

    return std::make_unique<Event>(
        event.type,
        event.sender_id,
        event.target_id,
        event.value
    );
}



// Event statistics (debugging)
class EventStats {

private:

    static std::map<EventType, int> event_counts;
    static std::map<EventType, float> total_processing_time;

public:

    static void record_event(const Event& e, float processing_time = 0) {

        event_counts[e.type]++;

        total_processing_time[e.type] += processing_time;
    }


    static void print_stats() {

        std::cout << "\n=== EVENT STATISTICS ===\n";

        for (const auto& pair : event_counts) {

            EventType type = pair.first;
            int count = pair.second;

            std::cout << event_type_to_string(type)
                      << ": " << count
                      << " events, avg time: "
                      << (total_processing_time[type] / count)
                      << "s\n";
        }

        std::cout << "========================\n";
    }


    static void reset() {

        event_counts.clear();
        total_processing_time.clear();
    }
};


// Initialize static members
std::map<EventType, int> EventStats::event_counts;
std::map<EventType, float> EventStats::total_processing_time;