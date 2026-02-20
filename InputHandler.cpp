#include "InputHandler.h"
#include <iostream>

char InputHandler::getInput() {
    char key;
    std::cin >> key;
    return key;
}
