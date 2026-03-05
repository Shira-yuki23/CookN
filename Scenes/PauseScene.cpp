 #include "PauseScene.h"

PauseScene::PauseScene() : Scene("Pause"), paused(true)
{
    std::cout << "[PauseScene] Created" << std::endl;
}

void PauseScene::pause()
{
    paused = true;
    std::cout << "[PauseScene] Game paused" << std::endl;
}

void PauseScene::resume()
{
    paused = false;
    std::cout << "[PauseScene] Game resumed" << std::endl;
}

void PauseScene::update(float deltaTime)
{
    if (paused)
    {
        std::cout << "[PauseScene] Game is currently paused" << std::endl;
    }
    else
    {
        std::cout << "[PauseScene] Returning to game..." << std::endl;
    }
}