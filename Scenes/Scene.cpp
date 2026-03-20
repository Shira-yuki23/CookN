 #include "Scene.h"
#include "Entity.h"
#include <algorithm>
#include <iostream>

Scene::Scene(const std::string& sceneName)
    : name(sceneName)
{
}

void Scene::setName(const std::string& sceneName)
{
    name = sceneName;
}

void Scene::update(float deltaTime)
{
    for (auto& entity : entities)
    {
        if (entity && entity->get_is_active())
        {
            entity->update(deltaTime);
        }
    }
}

void Scene::render()
{
    for (auto& entity : entities)
    {
        if (entity && entity->get_is_active())
        {
            entity->draw(0.0f);
        }
    }
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

void Scene::removeEntity(const std::string& entityId)
{
    entities.erase(
        std::remove_if(entities.begin(), entities.end(),
            [&entityId](const std::shared_ptr<Entity>& e) {
                return e && e->get_id() == entityId;
            }),
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