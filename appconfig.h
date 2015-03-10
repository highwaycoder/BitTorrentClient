#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <map>
#include <string>

class AppConfig
{
public:
    AppConfig();
    ~AppConfig();
    std::string getWithDefault(const std::string& key, const std::string& defaultValue);
private:
    std::map<std::string, std::string> configMap;
};

#endif // APPCONFIG_H
