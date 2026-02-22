#pragma once
#include <string>
#include <vector>

using namespace std;

// Enum for defining event types
enum class EventType {
    // Input Events
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
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

// Base Event class
class Event {
public:
    EventType type;     // Type of event
    string senderID;    // Optional: Who generated the event
    int value;          // Optional: Extra data (damage, score, etc.)

    Event(EventType t, const string& sender = "", int val = 0);
    virtual ~Event() = default;  // Virtual for polymorphic cleanup
};

// Input Event class
class InputEvent : public Event {
public:
    InputEvent(EventType t, const string& sender = "");
};

// Collision Event class
class CollisionEvent : public Event {
public:
    string otherEntityID;  // ID of the entity that collided with

    CollisionEvent(EventType t, const string& sender, const string& other, int val = 0);
};

// Combat Event class
class CombatEvent : public Event {
public:
    CombatEvent(EventType t, const string& sender, int damage = 0);
};

// Scene Event class
class SceneEvent : public Event {
public:
    string sceneName;  // The name of the scene to switch to

    SceneEvent(EventType t, const string& sender, const string& scene);
};

// Entity Lifecycle Event class
class EntityLifecycleEvent : public Event {
public:
    EntityLifecycleEvent(EventType t, const string& sender);
};
