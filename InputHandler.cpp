#include "InputHandler.h"
#include "Event.h"
#include <functional>

#ifdef _WIN32
#include <windows.h>
#endif

static EventType key_to_event(int key, bool pressed) {
    switch (key) {
        case VK_UP:    return pressed ? EventType::MOVE_UP   : EventType::MOVE_UP_RELEASE;
        case VK_DOWN:  return pressed ? EventType::MOVE_DOWN : EventType::MOVE_DOWN_RELEASE;
        case VK_LEFT:  return pressed ? EventType::MOVE_LEFT : EventType::MOVE_LEFT_RELEASE;
        case VK_RIGHT: return pressed ? EventType::MOVE_RIGHT: EventType::MOVE_RIGHT_RELEASE;
        case VK_SPACE: return pressed ? EventType::ATTACK : EventType::NONE;
        case VK_ESCAPE:return pressed ? EventType::QUIT : EventType::NONE;
        default: return EventType::NONE;
    }
}

void InputHandler::process_input() {
    previousKeyStates = keyStates;

    for (int key = 0; key < 256; key++) {
        bool pressed = (GetAsyncKeyState(key) & 0x8000) != 0;
        keyStates[key] = pressed;

        //fire event if map and callback
        if (on_input_event) {
            EventType type = key_to_event(key, pressed);
            if (type != EventType::NONE) {
                InputEvent e(type, "Player", key, pressed);
                on_input_event(e);
            }
        }
    }
}

bool InputHandler::is_key_pressed(int key) {
    if (key < 0 || key > 255) return false;
    return keyStates[key] && !previousKeyStates[key];
}

bool InputHandler::is_key_held(int key) {
    if (key < 0 || key > 255) return false;
    return keyStates[key];
}

bool InputHandler::is_key_released(int key) {
    if (key < 0 || key > 255) return false;
    return !keyStates[key] && previousKeyStates[key];
}