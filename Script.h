//
// Created by Ivan on 6/12/2022.
//

#ifndef EQSETTINGS_SCRIPT_H
#define EQSETTINGS_SCRIPT_H


#include <string>
#include <list>
#include <filesystem>

class Script
{
public:
    std::string m_name;
    std::list<std::string> m_script;
    bool m_loaded = false;

    bool load(const std::filesystem::path & path);
};


#endif //EQSETTINGS_SCRIPT_H
