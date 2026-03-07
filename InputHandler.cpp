#include "InputHandler.h"

#ifdef _WIN32
#include <windows.h>
#endif

void InputHandler::process_input() {
    // Store previous states
    previousKeyStates = keyStates;

#ifdef _WIN32
    for (int key = 0; key < 256; key++) {
        keyStates[key] = (GetAsyncKeyState(key) & 0x8000) != 0;
    }
#else
    //others
#endif
}

bool InputHandler::isKeyPressed(int key) {
    return keyStates[key] && !previousKeyStates[key];
}

bool InputHandler::isKeyHeld(int key) {
    return keyStates[key];
}

bool InputHandler::isKeyReleased(int key) {
    return !keyStates[key] && previousKeyStates[key];
}