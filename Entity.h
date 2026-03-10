#ifndef ENTITY_H
#define ENTITY_H

#include <string>


#include <iostream>

class Event; // Forward declaration

class Entity {
private:
    std::string id;
    std::string name;
    bool is_active;

<<<<<<< HEAD
protected:
    float x, y;       // Position
    float vx, vy;     // Velocity
    std::string tag;  // Optional tag
=======
    // new properties (minimal additions)
    float x = 0.0f, y = 0.0f;      // Position
    float vx = 0.0f, vy = 0.0f;    // Velocity
    std::string tag;               // Optional category/type
>>>>>>> origin/arshiyahera-patch-1

    static std::string generate_unique_id();

public:
    Entity(const std::string& entity_name);
    virtual ~Entity() {}

    // Accessors
    std::string get_id() const;
    std::string get_name() const;
    bool get_is_active() const;
    void set_is_active(bool active);

    // Position & velocity
    void set_position(float new_x, float new_y);
    float get_x() const;
    float get_y() const;

<<<<<<< HEAD
    void set_velocity(float new_vx, float new_vy);
=======
    // Optional event system
    virtual void onEvent(Event& event) {}

    // Getters / setters
    std::string getId() const;
    std::string getName() const;

    bool getIsActive() const;
    void setIsActive(bool active);


    // movement helpers
    void setPosition(float newX, float newY);
    void setVelocity(float newVx, float newVy);
    float getX() const;
    float getY() const;
>>>>>>> origin/arshiyahera-patch-1
    void move(float dx, float dy);

    void set_tag(const std::string& t);
    std::string get_tag() const;

    // Polymorphism
    virtual void update(float delta_time) = 0;
    virtual void draw(float alpha) = 0;
    virtual void on_event(const Event& event) = 0;

    //get
    float get_vx() const { return vx; }
    float get_vy() const { return vy; }
};

#endif
