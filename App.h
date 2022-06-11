//
// Created by Ivan on 6/1/2022.
//

#ifndef EQSETTINGS_APP_H
#define EQSETTINGS_APP_H

#include <unordered_map>
#include <queue>

#include "Configurator.h"

class App : public Configurator
{
private:
    std::unordered_map<std::string, void(App::*)(std::queue<std::string> & commandQueue)> m_commands;

public:
    App();
    ~App() = default;
    bool runCommand(std::queue<std::string> &commandQueue);
    void readINI(const std::string &configFilePath);

private:
    void assignCommands();
    bool parseCommand(const std::string &command);
};


#endif //EQSETTINGS_APP_H
