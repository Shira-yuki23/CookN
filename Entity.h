#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <memory>

class Entity {
protected:
    std::string id;
    std::string name;
    bool isActive;
    
public:
    Entity(const std::string& entityName);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;
    void setIsActive(bool active);
};

#endif 