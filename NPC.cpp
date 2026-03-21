#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, float start_x, float start_y, int hp)
    : SpatialEntity(name, start_x, start_y),
      health(hp),
      max_health(hp),
      is_hostile(false),
      moving_left(true),
      speed(2.0f)
{
    set_size(1.0f, 1.0f);
}

void NPC::update(float delta_time)
{
    if (!get_is_active())
        return;

    // simple patrol AI
    if (moving_left)
        set_velocity(-speed, 0);
    else
        set_velocity(speed, 0);

    move(get_vx() * delta_time, get_vy() * delta_time);

    // simple patrol bounds
    if (get_x() < 0)
        moving_left = false;

    if (get_x() > 20)
        moving_left = true;
}

void NPC::draw(float alpha)
{
    
    std::cout << "NPC [" << get_name() << "] "
              << "pos(" << get_x() << "," << get_y() << ") "
              << "HP:" << health << "/" << max_health
              << std::endl;
    
}

void NPC::on_event(const Event& event)
{
    if (!event.is_for(get_id()))
        return;

    switch (event.type)
    {
        // input events (ignored by NPC)
        case EventType::MOVE_UP:
        case EventType::MOVE_DOWN:
        case EventType::MOVE_LEFT:
        case EventType::MOVE_RIGHT:
        case EventType::MOVE_UP_RELEASE:
        case EventType::MOVE_DOWN_RELEASE:
        case EventType::MOVE_LEFT_RELEASE:
        case EventType::MOVE_RIGHT_RELEASE:
            break;

        // player interaction
        case EventType::INTERACT:
            std::cout << get_name() << " says hello.\n";
            break;

        case EventType::ATTACK:
            std::cout << get_name() << " is being attacked!\n";
            break;

        case EventType::PAUSE:
        case EventType::QUIT:
            break;

        // physics
        case EventType::COLLISION:
            std::cout << get_name() << " collided with something.\n";
            moving_left = !moving_left;
            break;

        case EventType::BLOCKED:
            moving_left = !moving_left;
            break;

        case EventType::ITEM_COLLECTED:
            break;

        // combat
        case EventType::DAMAGE_TAKEN:
            take_damage(event.value);
            break;

        case EventType::HEAL:
            heal(event.value);
            break;

        case EventType::DEATH:
            set_is_active(false);
            std::cout << get_name() << " died.\n";
            break;

        // scene system
        case EventType::SCENE_SWITCH:
        case EventType::LEVEL_COMPLETE:
        case EventType::GAME_OVER:
            break;

        // lifecycle
        case EventType::SPAWN:
            // std::cout << get_name() << " spawned.\n";
            break;

        case EventType::DESTROY:
            set_is_active(false);
            std::cout << get_name() << " destroyed.\n";
            break;

        case EventType::NONE:
        default:
            break;
    }
}

void NPC::take_damage(int amount)
{
    health -= amount;

    std::cout << get_name() << " took " << amount << " damage.\n";

    if (health <= 0)
    {
        health = 0;
        set_is_active(false);

        std::cout << get_name() << " has died.\n";
    }
}

void NPC::heal(int amount)
{
    health += amount;

    if (health > max_health)
        health = max_health;

    std::cout << get_name() << " healed " << amount << " HP.\n";
}

bool NPC::is_alive() const
{
    return health > 0;
}

char NPC::get_symbol() const
{
    return 'N';
}