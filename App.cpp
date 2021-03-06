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

bool App::runCommand (std::queue<std::string> & cmdQueue)
{
    auto command = cmdQueue.front();

    auto it = m_commands.find(command);

    if (it != m_commands.end())
    {
        cmdQueue.pop();
        (this->*it->second)(cmdQueue);
        return true;
    }

    return false;
}

void App::assignCommands ()
{
    m_commands["off"] = &App::turnOff;
    m_commands["on"] = &App::turnOn;
    m_commands["all"] = &App::turnOn;
    m_commands["switch"] = &App::switchPlugin;
}

bool App::parseCommand (const std::string &command)
{

}

void App::readINI (const std::string &configFilePath)
{
    std::ifstream iniFile(configFilePath);
    if (iniFile.fail()) {
        std::ofstream outFile(configFilePath);
        if (outFile.fail()) {
            std::cerr << "Failed to create file: " << configFilePath << std::endl;
            return;
        }
        outFile << R"(configPath="C:\Program Files\EqualizerAPO\config\config.txt")";
        outFile.close();
        return;
    }

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
