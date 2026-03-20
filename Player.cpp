#include "Player.h"
#include "Event.h"
#include <iostream>

using namespace std;

Player::Player(float startX, float startY)
    : SpatialEntity("Player", startX, startY)
{
    set_velocity(0.0f, 0.0f);
}

void Player::update(float delta_time)
{
    // Move according to velocity
    set_position(
        get_x() + get_vx() * delta_time,
        get_y() + get_vy() * delta_time
    );
}

void Player::draw(float alpha)
{
    /*
    cout << "Player at ("
         << static_cast<int>(get_x()) << ","
         << static_cast<int>(get_y()) << ")\n";
    */
}

void Player::on_event(const Event& event)
{
    if (auto input = dynamic_cast<const InputEvent*>(&event))
    {
        float speed = 100.0f; // units per second

        switch (input->type)
        {
            case EventType::MOVE_UP:
                set_velocity(get_vx(), -speed);
                break;
            case EventType::MOVE_DOWN:
                set_velocity(get_vx(), speed);
                break;
            case EventType::MOVE_LEFT:
                set_velocity(-speed, get_vy());
                break;
            case EventType::MOVE_RIGHT:
                set_velocity(speed, get_vy());
                break;

            case EventType::MOVE_UP_RELEASE:
            case EventType::MOVE_DOWN_RELEASE:
                set_velocity(get_vx(), 0.0f);
                break;
            case EventType::MOVE_LEFT_RELEASE:
            case EventType::MOVE_RIGHT_RELEASE:
                set_velocity(0.0f, get_vy());
                break;

            case EventType::ATTACK:
                // cout << get_name() << " attacks!\n";
                break;

            default:
                break;
        }
    }
}