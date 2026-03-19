 #include "CreditsScene.h"

CreditsScene::CreditsScene() : Scene("Credits")
{
    std::cout << "[CreditsScene] Created" << std::endl;
}

void CreditsScene::update(float deltaTime)
{
    std::cout << "[CreditsScene] Displaying credits..." << std::endl;
}