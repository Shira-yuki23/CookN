#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <memory>
#include <chrono>

enum class EventType {

    NONE,

    // Input Events
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,

    MOVE_UP_RELEASE,
    MOVE_DOWN_RELEASE,
    MOVE_LEFT_RELEASE,
    MOVE_RIGHT_RELEASE,

    ATTACK,
    INTERACT,
    PAUSE,
    QUIT,

    // Collision Events
    COLLISION,
    BLOCKED,
    ITEM_COLLECTED,

    // Combat Events
    DAMAGE_TAKEN,
    HEAL,
    DEATH,

    // Scene Events
    SCENE_SWITCH,
    LEVEL_COMPLETE,
    GAME_OVER,

    // Entity Lifecycle
    SPAWN,
    DESTROY
};

class Event {
public:
    EventType type;
    std::string sender_id;
    std::string target_id;
    int value;

    std::chrono::steady_clock::time_point timestamp;

    Event(EventType t,
          const std::string& sender = "",
          const std::string& target = "",
          int val = 0)
        : type(t),
          sender_id(sender),
          target_id(target),
          value(val),
          timestamp(std::chrono::steady_clock::now())
    {}

    virtual ~Event() = default;

    bool is_for(const std::string& entity_id) const {
        return target_id.empty() || target_id == entity_id;
    }

    float get_age_in_seconds() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<float>(now - timestamp).count();
    }
};

class InputEvent : public Event {
public:
    int key_code;
    bool is_held;

    InputEvent(EventType t,
               const std::string& sender = "",
               int key = 0,
               bool held = false)
        : Event(t, sender),
          key_code(key),
          is_held(held)
    {}
};

class CollisionEvent : public Event {
public:
    std::string other_entity_id;
    float collision_x, collision_y;

    CollisionEvent(const std::string& sender,
                   const std::string& other,
                   float x = 0,
                   float y = 0)
        : Event(EventType::COLLISION, sender, other),
          other_entity_id(other),
          collision_x(x),
          collision_y(y)
    {}
};

class CombatEvent : public Event {
public:
    int damage_amount;
    std::string attacker_id;
    std::string defender_id;

    CombatEvent(const std::string& attacker,
                const std::string& defender,
                int damage)
        : Event(EventType::DAMAGE_TAKEN, attacker, defender, damage),
          damage_amount(damage),
          attacker_id(attacker),
          defender_id(defender)
    {}

    static CombatEvent create_heal(const std::string& healer,
                                   const std::string& healed,
                                   int amount) {
        CombatEvent e(healer, healed, amount);
        e.type = EventType::HEAL;
        return e;
    }
};

class SceneEvent : public Event {
public:
    std::string scene_name;
    std::string previous_scene;

    SceneEvent(EventType t,
               const std::string& sender,
               const std::string& scene,
               const std::string& previous = "")
        : Event(t, sender),
          scene_name(scene),
          previous_scene(previous)
    {}

    static SceneEvent create_switch(const std::string& sender,
                                    const std::string& new_scene,
                                    const std::string& old_scene = "") {
        return SceneEvent(EventType::SCENE_SWITCH, sender, new_scene, old_scene);
    }
};

class EntityLifecycleEvent : public Event {
public:
    std::string entity_type;
    float spawn_x, spawn_y;

    EntityLifecycleEvent(EventType t,
                         const std::string& entity_id,
                         const std::string& type = "",
                         float x = 0,
                         float y = 0)
        : Event(t, entity_id),
          entity_type(type),
          spawn_x(x),
          spawn_y(y)
    {}

    static EntityLifecycleEvent create_spawn(const std::string& entity_id,
                                             const std::string& type,
                                             float x,
                                             float y) {
        return EntityLifecycleEvent(EventType::SPAWN, entity_id, type, x, y);
    }

    static EntityLifecycleEvent create_destroy(const std::string& entity_id) {
        return EntityLifecycleEvent(EventType::DESTROY, entity_id);
    }
};

#endif