#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity {
protected:               
    std::string id;
    std::string name;
    bool isActive;

public:
    Entity(const std::string& entityName);
    virtual ~Entity() = default;

    // abstract methods for derived classes to implement
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;
    void setIsActive(bool active);
};

#endif // ENTITY_H
