#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <unordered_map>

class InputHandler {
private:
    std::unordered_map<int, bool> keyStates;
    std::unordered_map<int, bool> previousKeyStates;

public:
    void process_input();

    bool isKeyPressed(int key);

    bool isKeyHeld(int key);

    bool isKeyReleased(int key);
};

#endif