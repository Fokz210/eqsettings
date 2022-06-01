//
// Created by Ivan on 5/28/2022.
//

#include <fstream>
#include "Configurator.h"

Configurator::Configurator (const std::string & configFilePath) :
    m_pluginLines(std::vector<PluginConfig>()),
    m_disableAutoSave(false)
{
    setConfigFilePath (configFilePath);
    loadConfig(configFilePath);
}

Configurator::Configurator () :
    m_pluginLines(std::vector<PluginConfig>()),
    m_disableAutoSave(false)
{
}

void Configurator::loadConfig (const std::string &configFilePath)
{
    std::ifstream configFile(configFilePath);
    std::string line;
    while (std::getline(configFile, line))
    {
        m_pluginLines.emplace_back(line);
    }

}

void Configurator::printConfig (std::ostream &out) const
{
    for (const auto &pluginLine : m_pluginLines)
    {
        pluginLine.printConfig(out);
        out << std::endl;
    }
}

void Configurator::saveConfig (const std::string &config) const
{
    std::ofstream out(config);
    printConfig(out);


}

void Configurator::setPlugins (const std::vector <PluginConfig> &plugins)
{
    m_pluginLines = plugins;
}

std::vector <PluginConfig> Configurator::getPlugins () const
{
    return m_pluginLines;
}

PluginConfig &Configurator::operator[] (const size_t &index)
{
    return m_pluginLines[index];
}

void Configurator::disableAll ()
{
    for (auto &pluginLine : m_pluginLines)
    {
        pluginLine.setActive(false);
    }
}

void Configurator::disableAutoSave ()
{
    m_disableAutoSave = true;
}

void Configurator::enableAutoSave ()
{
    m_disableAutoSave = false;
}

Configurator::~Configurator ()
{
    if (!m_disableAutoSave)
    {
        saveConfig(m_configFilePath);
    }
}

void Configurator::enableAll ()
{
    for (auto &pluginLine : m_pluginLines)
    {
        pluginLine.setActive(true);

        std::cout << "activated plugin" << std::endl;
    }
}

void Configurator::setState (int index, bool state)
{
    m_pluginLines[index].setActive(state);
}

bool Configurator::getState (int index) const
{
    return m_pluginLines[index].getActive();
}

void Configurator::setConfigFilePath (const std::string &configFilePath)
{
    m_configFilePath = configFilePath;
}

std::string Configurator::getConfigFilePath () const
{
    return m_configFilePath;
}

void Configurator::loadConfig ()
{
    loadConfig(m_configFilePath);
}
