//
// Created by Ivan on 6/12/2022.
//

#ifndef EQSETTINGS_SCRIPTLOADER_H
#define EQSETTINGS_SCRIPTLOADER_H

#include <filesystem>
#include <string>
#include <unordered_set>
#include <list>
#include <unordered_map>

#include "Script.h"

class ScriptLoader
{
private:
    std::string m_scriptsFolderPath;
    std::unordered_map<std::string, Script> m_scripts;

public:
    ScriptLoader();
    explicit ScriptLoader(std::string scriptsFolderPath);

    void setScriptsFolderPath(std::string scriptsFolderPath);
    std::string getScriptsFolderPath() const;

    void scanScripts();
    void preload();

    std::unordered_map<std::string, Script> getScriptSet() const;
    bool hasScript(const std::string& scriptName) const;

    Script getScript(std::string scriptName);
};


#endif //EQSETTINGS_SCRIPTLOADER_H
