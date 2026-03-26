 #include "Engine.h"
#include "Player.h"
#include "NPC.h"
#include "Scene.h"
#include "EngineExceptions.h"


#include "Scenes/SceneManager.h"
#include "Scenes/SceneFactory.h"

#include "Utils/ConfigManager.h"
#include "Utils/Timer.h"
#include "Utils/Logger.h"

#include <memory>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() 
{
    try 
    {
        Engine engine;
        engine.initialize();
        auto player = std::make_shared<Player>(5.0f, 5.0f);
        auto guard1 = std::make_shared<NPC>("Guard_Alpha", 15.0f, 5.0f);
        auto guard2 = std::make_shared<NPC>("Guard_Bravo", 10.0f, 15.0f);
        auto villager1 = std::make_shared<NPC>("Villager_A", 2.0f, 10.0f);
        auto villager2 = std::make_shared<NPC>("Villager_B", 18.0f, 12.0f);
        auto boss = std::make_shared<NPC>("Boss", 35.0f, 20.0f, 500);

        engine.add_entity(player);
        engine.add_entity(guard1);
        engine.add_entity(guard2);
        engine.add_entity(villager1);
        engine.add_entity(villager2);
        engine.add_entity(boss);

        
        auto sceneManager = std::make_shared<SceneManager>();

        sceneManager->createAndAddScene("Menu");
        sceneManager->createAndAddScene("Game");
        sceneManager->createAndAddScene("Pause");
        sceneManager->createAndAddScene("Settings");
        sceneManager->createAndAddScene("Credits");

        sceneManager->switchScene("Menu");
        sceneManager->printAllScenes();

        // Demonstrate transitions
        sceneManager->switchScene("Game");
        sceneManager->switchScene("Pause");
        sceneManager->goBack(); // back to Game

        auto currentScene = sceneManager->getCurrentScene();
        if (currentScene)
        {
            std::cout << "Current Scene: " 
                      << currentScene->getName() << std::endl;

            currentScene->update(0.016f); // simulate frame update
        }

    
        ConfigManager::GetInstance()->SetValue("volume", 75);
        int volume = ConfigManager::GetInstance()->GetValueInt("volume");
        std::cout << "Volume: " << volume << std::endl;

        // ✅ Timer
        Timer timer;
        timer.update(1.0f);

        if (timer.hasElapsed(1.0f))
        {
            std::cout << "1 second elapsed!" << std::endl;
        }

        // ✅ Logger
        ConsoleLogger logger;
        logger.log("Game initialized successfully", LogLevel::INFO);

    
        engine.run();
        engine.shutdown();
    }
    catch (const EngineException& e)
    {
        std::cerr << "[CRITICAL ERROR] " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cerr << "[UNKNOWN ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
