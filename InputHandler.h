#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <unordered_map>
#include <functional>
#include "Event.h"

class InputHandler {
private:
    std::unordered_map<int, bool> keyStates;
    std::unordered_map<int, bool> previousKeyStates;

public:
    void process_input();
    bool is_key_pressed(int key);   
    bool is_key_held(int key);      
    bool is_key_released(int key);

    std::function<void(const InputEvent&)> on_input_event;

};

#endif