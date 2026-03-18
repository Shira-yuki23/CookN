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

protected:
    float x, y;       // Position
    float vx, vy;     // Velocity
    std::string tag;  // Optional tag

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

    void set_velocity(float new_vx, float new_vy);
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
