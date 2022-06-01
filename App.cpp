//
// Created by Ivan on 6/1/2022.
//

#include <fstream>
#include "App.h"

App::App () :
    Configurator()
{
    readINI("EQSettings.ini");
    loadConfig();
    assignCommands();
}

bool App::runCommand (const std::string &command)
{
    auto active = 1;

    if (parseCommand (command))
    {
        return true;
    }
    else
    {
        active = std::strtol(command.c_str(), nullptr, 10);
        active = std::max (--active, 0);
    }

    if (active > getPlugins().size() - 1)
        active = 0;

    setState(active, !getState(active));

    return true;
}

void App::assignCommands ()
{
    m_commands["off"] = &App::disableAll;
    m_commands["all"] = &App::enableAll;
}

bool App::parseCommand (const std::string &command)
{
    auto it = m_commands.find(command);

    if (it != m_commands.end())
    {
        (this->*it->second)();
        return true;
    }

    return false;
}

void App::readINI (const std::string &configFilePath)
{
    std::ifstream iniFile (configFilePath);
    for (std::string line; std::getline(iniFile, line);)
    {
        if (line.empty())
            continue;

        if (line.find("configPath") != std::string::npos)
        {
            std::string buffer = line.substr (line.find('=') + 1);
            buffer = buffer.substr (1, buffer.size() - 2);
            setConfigFilePath(buffer);
            continue;
        }
    }
}
