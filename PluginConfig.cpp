//
// Created by Ivan on 5/28/2022.
//

#include <sstream>
#include <iostream>
#include "PluginConfig.h"

PluginConfig::PluginConfig (const std::string &pluginLine) :
    m_type(""),
    m_params(""),
    m_active(true)
{
    loadConfig(pluginLine);
}

PluginConfig::PluginConfig () :
    m_type(""),
    m_params(""),
    m_active(true)
{

}

void PluginConfig::setType (const std::string &type)
{
    m_type = type;
}

void PluginConfig::setParams (std::string &params)
{
    m_params = params;
}

void PluginConfig::setActive (bool active)
{
    m_active = active;
}

std::string PluginConfig::getType () const
{
    return m_type;
}

std::string PluginConfig::getParams () const
{
    return m_params;
}

bool PluginConfig::isActive () const
{
    return m_active;
}

void PluginConfig::loadConfig (const std::string &configLine)
{
    std::string buffer = configLine;

    if (configLine.empty())
    {
        return;
    }

    if (configLine.front() == '#')
    {
        buffer = buffer.substr (2);
        setActive (false);
    }

    m_type = buffer.substr (0, buffer.find(' '));
    m_type = m_type.substr (0, m_type.find(':'));

    buffer = buffer.substr (buffer.find(' ') + 1);
    m_params = buffer;
}

void PluginConfig::printConfig (std::ostream & out) const
{
    if (!m_active)
        out << "# ";

    out << m_type << ": ";

    out << m_params;
}
