 #include "MenuScene.h"

MenuScene::MenuScene() : Scene("Menu") {
    std::cout << "[MenuScene] Created" << std::endl;
}

void MenuScene::update(float deltaTime) {
    std::cout << "[MenuScene] Updating..." << std::endl;
}