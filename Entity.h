#ifndef ENTITY_H
#define ENTITY_H

#include <string>

<<<<<<< HEAD
class Entity {
private:
=======
#include <iostream>

class Event; // Forward declaration
//>>>>>>> origin/arshiyahera-patch-1

class Entity {
protected:
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
    std::string id;
    std::string name;
    bool isActive;

<<<<<<< HEAD
protected:
    float x, y;       // Position
    float vx, vy;     // Velocity
    std::string tag;  // Optional tag
=======
    // ✅ Added new properties (minimal additions)
    float x = 0.0f, y = 0.0f;      // Position
    float vx = 0.0f, vy = 0.0f;    // Velocity
    std::string tag;               // Optional category/type
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b

    static std::string generateUniqueId();

public:
    Entity(const std::string& entityName);
<<<<<<< HEAD
    virtual ~Entity() {}
=======
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
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b

    // Accessors
    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;
    void setIsActive(bool active);

    // Position & velocity
    void setPosition(float newX, float newY);
    float getX() const;
    float getY() const;

<<<<<<< HEAD
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
=======
    // ✅ New movement helpers
    void setPosition(float newX, float newY);
    void setVelocity(float newVx, float newVy);
    float getX() const;
    float getY() const;
    void move(float dx, float dy);

    void setTag(const std::string& t);
    std::string getTag() const;
//>>>>>>> origin/arshiyahera-patch-1
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
};

#endif