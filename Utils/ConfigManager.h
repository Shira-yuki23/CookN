 #pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class ConfigManager
{
private:
    std::unordered_map<std::string, std::string> settings;
    static ConfigManager* instance;
    ConfigManager() = default; // private constructor

public:
    // Singleton accessor
    static ConfigManager* GetInstance();

    // Function overloading to set different types
    void SetValue(const std::string& key, const std::string& value);
    void SetValue(const std::string& key, int value);
    void SetValue(const std::string& key, float value);

    // Function overloading to get different types
    std::string GetValue(const std::string& key) const;
    int GetValueInt(const std::string& key) const;
    float GetValueFloat(const std::string& key) const;

    // Optional: print all settings
    void PrintAll() const;
};