 #pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

template<typename T>
class ResourceManager
{
private:
    std::unordered_map<std::string, std::shared_ptr<T>> resources;

public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    // Load resource
    void Load(const std::string& key, std::shared_ptr<T> resource)
    {
        resources[key] = resource;
    }

    // Operator overloading: access resource like array
    std::shared_ptr<T> operator[](const std::string& key)
    {
        if (resources.find(key) != resources.end())
            return resources[key];
        return nullptr;
    }

    // Function to unload resource
    void Unload(const std::string& key)
    {
        resources.erase(key);
    }

    void PrintAll() const
    {
        std::cout << "=== Resources Loaded ===" << std::endl;
        for (auto& pair : resources)
            std::cout << " - " << pair.first << std::endl;
    }
};