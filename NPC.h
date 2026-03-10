#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"

#include "event.h"
#include <string>

class NPC : public SpatialEntity {
private:
    int health;
    int max_health;

    bool is_hostile;
    bool moving_left;

    float speed;

public:
    NPC(const std::string& name, float start_x, float start_y, int hp = 100);

    // core behaviour
    void update(float delta_time) override;
    void draw(float alpha) override;
    void on_event(const Event& event) override;

    // combat helpers
    void take_damage(int amount);
    void heal(int amount);

    bool is_alive() const;

    // rendering
    char get_symbol() const override;
};

#endif