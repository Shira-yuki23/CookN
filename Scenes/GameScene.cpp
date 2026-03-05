 #include "GameScene.h"

GameScene::GameScene() : Scene("Game"), isRunning(false), elapsedTime(0.0f)
{
    std::cout << "[GameScene] Created" << std::endl;
}

void GameScene::startGame()
{
    isRunning = true;
    elapsedTime = 0.0f;

    std::cout << "[GameScene] Game started" << std::endl;
}

void GameScene::stopGame()
{
    isRunning = false;

    std::cout << "[GameScene] Game stopped" << std::endl;
}

void GameScene::update(float deltaTime)
{
    if (!isRunning)
    {
        std::cout << "[GameScene] Waiting to start..." << std::endl;
        return;
    }

    elapsedTime += deltaTime;

    std::cout << "[GameScene] Running. Time elapsed: "
              << elapsedTime << std::endl;

}