#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Event; // Forward declaration

class Entity {
protected:
    std::string id;
    std::string name;
    bool isActive;

    // ✅ Added new properties (minimal additions)
    float x = 0.0f, y = 0.0f;      // Position
    float vx = 0.0f, vy = 0.0f;    // Velocity
    std::string tag;               // Optional category/type

    static std::string generateUniqueId();

public:
    Entity(const std::string& entityName);
    virtual ~Entity() {
        std::cout << "Entity destroyed: " << name << std::endl;
    }

    // Core functions
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;  // kept render() (renamed from draw to match old)

    // Optional event system
    virtual void onEvent(Event& event) {}

    // Getters / setters
    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;
    void setIsActive(bool active);

    // ✅ New movement helpers
    void setPosition(float newX, float newY);
    void setVelocity(float newVx, float newVy);
    float getX() const;
    float getY() const;
    void move(float dx, float dy);

    void setTag(const std::string& t);
    std::string getTag() const;
};

#endif