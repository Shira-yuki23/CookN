#ifndef ENTITY_H
#define ENTITY_H

#include <string>

<<<<<<< HEAD
#include <iostream>

class Event; // Forward declaration
=======
>>>>>>> origin/main
class Entity {
private:
    std::string id;
    std::string name;
    bool is_active;

protected:
    float x, y;       // Position
    float vx, vy;     // Velocity
    std::string tag;  // Optional tag

    static std::string generate_unique_id();

public:
    Entity(const std::string& entity_name);
    virtual ~Entity() {}

<<<<<<< HEAD

    // Core functions
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;  // kept render() (renamed from draw to match old)
=======
    // Accessors
    std::string get_id() const;
    std::string get_name() const;
    bool get_is_active() const;
    void set_is_active(bool active);
>>>>>>> origin/main

    // Position & velocity
    void set_position(float newX, float newY);
    float get_x() const;
    float get_y() const;

<<<<<<< HEAD
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

=======
    void set_velocity(float newVx, float newVy);
    void move(float dx, float dy);

    void set_tag(const std::string& t);
    std::string get_tag() const;

    // Polymorphism
    virtual void update() = 0;
    virtual void draw() = 0;

    //get
    float get_vx() const { return vx; }
    float get_vy() const { return vy; }
>>>>>>> origin/main
};

#endif
