 #include "ConfigManager.h"
#include <sstream>

ConfigManager* ConfigManager::instance = nullptr;

ConfigManager* ConfigManager::GetInstance()
{
    if (!instance)
        instance = new ConfigManager();
    return instance;
}

// SetValue overloads
void ConfigManager::SetValue(const std::string& key, const std::string& value)
{
    settings[key] = value;
}

void ConfigManager::SetValue(const std::string& key, int value)
{
    settings[key] = std::to_string(value);
}

void ConfigManager::SetValue(const std::string& key, float value)
{
    settings[key] = std::to_string(value);
}

// GetValue overloads
std::string ConfigManager::GetValue(const std::string& key) const
{
    auto it = settings.find(key);
    return it != settings.end() ? it->second : "";
}

int ConfigManager::GetValueInt(const std::string& key) const
{
    std::string val = GetValue(key);
    return val.empty() ? 0 : std::stoi(val);
}

float ConfigManager::GetValueFloat(const std::string& key) const
{
    std::string val = GetValue(key);
    return val.empty() ? 0.0f : std::stof(val);
}

void ConfigManager::PrintAll() const
{
    std::cout << "=== Config Settings ===" << std::endl;
    for (auto& pair : settings)
    {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }
}