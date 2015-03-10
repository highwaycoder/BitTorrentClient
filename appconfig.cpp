#include "appconfig.h"
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <iostream>

const std::string CONFIG_FILE_NAME = "config.json";

AppConfig::AppConfig()
{
    QString configFileName = QString::fromStdString(CONFIG_FILE_NAME);
    QFile configFile(configFileName);
    QByteArray configJsonRaw;
    QJsonDocument configJson;
    if(configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while(!configFile.atEnd()) {
            QByteArray configLine = configFile.readLine();
            configJsonRaw.append(configLine);
        }
        configJson.fromJson(configJsonRaw);
    } else {
        std::cout << "Warning: could not read file " << configFile.fileName().toStdString() << std::endl;
    }
}

AppConfig::~AppConfig()
{

}

std::string AppConfig::getWithDefault(const std::string &key, const std::string &defaultValue)
{
    std::string returnValue;
    if(configMap.count(key) > 0) {
        returnValue = configMap[key];
    } else {
        returnValue = defaultValue;
    }
    return returnValue;
}
