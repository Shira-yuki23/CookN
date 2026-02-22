#include "Event.h"

// Base Event class constructor
Event::Event(EventType t, const string& sender, int val)
    : type(t), senderID(sender), value(val) {}

// Input Event class constructor
InputEvent::InputEvent(EventType t, const string& sender)
    : Event(t, sender) {}

// Collision Event class constructor
CollisionEvent::CollisionEvent(EventType t, const string& sender, const string& other, int val)
    : Event(t, sender, val), otherEntityID(other) {}

// Combat Event class constructor
CombatEvent::CombatEvent(EventType t, const string& sender, int damage)
    : Event(t, sender, damage) {}

// Scene Event class constructor
SceneEvent::SceneEvent(EventType t, const string& sender, const string& scene)
    : Event(t, sender), sceneName(scene) {}

// Entity Lifecycle Event class constructor
EntityLifecycleEvent::EntityLifecycleEvent(EventType t, const string& sender)
    : Event(t, sender) {}
