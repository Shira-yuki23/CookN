#include "entity_manager.h"
#include <algorithm>

EntityManager::~EntityManager()
{
    for (auto entity : entities)
    {
        delete entity;
    }
    entities.clear();
}

void EntityManager::addEntity(Entity* entity)
{
    entities.push_back(entity);
}

void EntityManager::removeEntity(const std::string& id)
{
    entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [&id](Entity* e)
            {
                if (e->getId() == id)
                {
                    delete e;
                    return true;
                }
                return false;
            }),
        entities.end());
}

Entity* EntityManager::getEntityById(const std::string& id)
{
    for (auto entity : entities)
    {
        if (entity->getId() == id)
        {
            return entity;
        }
    }
    return nullptr;
}

void EntityManager::updateAll(float deltaTime)
{
    for (auto entity : entities)
    {
        if (entity->getIsActive())
        {
            entity->update(deltaTime);
        }
    }
}

void EntityManager::renderAll()
{
    for (auto entity : entities)
    {
        if (entity->getIsActive())
        {
            entity->render();
        }
    }
}

void EntityManager::broadcastEvent(Event& event)
{
    for (auto entity : entities)
    {
        if (entity->getIsActive())
        {
            entity->onEvent(event);
        }
    }
}

const std::vector<Entity*>& EntityManager::getEntities() const
{
    return entities;
}