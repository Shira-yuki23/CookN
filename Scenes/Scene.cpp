 #include "Scene.h"
#include <algorithm>

Scene::Scene(const std::string& sceneName)
    : name(sceneName)
{
}

void Scene::update(float deltaTime)
{
    // empty for now
}

void Scene::addEntity(std::shared_ptr<Entity> entity)
{
    entities.push_back(entity);
}

void Scene::removeEntity(std::shared_ptr<Entity> entity)
{
    entities.erase(
        std::remove(entities.begin(), entities.end(), entity),
        entities.end()
    );
}

std::string Scene::getName() const
{
    return name;
}

std::vector<std::shared_ptr<Entity>> Scene::getEntities() const
{
    return entities;
}