#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
private:
    std::string id;
    std::string name;
    bool isActive;

protected:
    float x, y;       // Position
    float vx, vy;     // Velocity
    std::string tag;  // Optional tag

    static std::string generateUniqueId();

public:
    Entity(const std::string& entityName);
    virtual ~Entity() {}

    // Accessors
    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;
    void setIsActive(bool active);

    // Position & velocity
    void setPosition(float newX, float newY);
    float getX() const;
    float getY() const;

    void setVelocity(float newVx, float newVy);
    void move(float dx, float dy);

    void setTag(const std::string& t);
    std::string getTag() const;

    // Polymorphism
    virtual void update() = 0;
    virtual void draw() = 0;

    //get
    float getVX() const { return vx; }
    float getVY() const { return vy; }
};

#endif