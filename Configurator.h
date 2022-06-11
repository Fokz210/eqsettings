//
// Created by Ivan on 5/28/2022.
//

#ifndef EQSETTINGS_CONFIGURATOR_H
#define EQSETTINGS_CONFIGURATOR_H
#endif

#ifndef __CONFIGURATOR_CMD__
#define __CONFIGURATOR_CMD__

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "PluginConfig.h"

constexpr auto DEFAULT_CONFIG_FILE_PATH = R"(C:\Program Files\EqualizerAPO\config\config.txt)";

class Configurator
{
private:
    std::vector<PluginConfig> m_pluginLines;
    bool m_disableAutoSave = false;
    std::string m_configFilePath = DEFAULT_CONFIG_FILE_PATH;

public:
    explicit Configurator(const std::string & configFilePath);
    Configurator();
    ~Configurator();

    void loadConfig(const std::string & configFilePath);
    void loadConfig();
    void printConfig(std::ostream & out = std::cout) const;
    void saveConfig(const std::string & configFilePath) const;

    void clearConfig();

    void setState(int index, bool state);
    bool getState(int index) const;

    void setPlugins(const std::vector<PluginConfig> & plugins);
    std::vector<PluginConfig> getPlugins() const;

    void disableAutoSave();
    void enableAutoSave();

    __CONFIGURATOR_CMD__ void disableAll(std::queue<std::string> & cmdQueue);
    __CONFIGURATOR_CMD__ void enableAll(std::queue<std::string> & cmdQueue);
    __CONFIGURATOR_CMD__ void switchPlugin(std::queue<std::string> & cmdQueue);

    [[deprecated("Use getState instead")]]
    PluginConfig &operator[](const size_t &index);

    void setConfigFilePath(const std::string & configFilePath);
    std::string getConfigFilePath() const;
};


#endif //EQSETTINGS_CONFIGURATOR_H
