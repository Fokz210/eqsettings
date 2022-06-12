//
// Created by Ivan on 6/12/2022.
//
#include <fstream>
#include <iostream>

#include "project.h"
#include "Script.h"

bool Script::load (const std::filesystem::path &path)
{
    m_name = path.filename().string();
    std::ifstream scriptFile(path);

    std::string version;
    scriptFile >> version;

    if (version < EQSETTINGS_VERSION)
        return false;

    std::string cmd;
    while (scriptFile >> cmd)
    {
        m_script.push_back (cmd);
    }

    scriptFile.close();

    m_loaded = true;
    return true;
}
