//
// Created by Ivan on 6/12/2022.
//

#include <iostream>
#include <utility>
#include "ScriptLoader.h"

ScriptLoader::ScriptLoader () :
    m_scripts()
{

}

ScriptLoader::ScriptLoader (std::string scriptsFolderPath) :
    m_scripts(),
    m_scriptsFolderPath(std::move(scriptsFolderPath))
{
    scanScripts();
}

void ScriptLoader::setScriptsFolderPath (std::string scriptsFolderPath)
{
    m_scriptsFolderPath = std::move(scriptsFolderPath);
}

std::string ScriptLoader::getScriptsFolderPath () const
{
    return m_scriptsFolderPath;
}

void ScriptLoader::scanScripts ()
{
    m_scripts.clear();

    std::filesystem::path path(m_scriptsFolderPath);
    if (std::filesystem::is_directory (path)) {
        for (const auto & entry : std::filesystem::directory_iterator(path)) {

            m_scripts.insert ({entry.path().filename().string(), Script()});

        }
    }
}

std::unordered_map <std::string, Script> ScriptLoader::getScriptSet () const
{
    return m_scripts;
}

bool ScriptLoader::hasScript (const std::string& scriptName) const
{
    if (scriptName.find (".eqs") == std::string::npos)
        return m_scripts.count(scriptName + ".eqs");

    return m_scripts.count(scriptName);
}

void ScriptLoader::preload ()
{
    if (m_scripts.empty())
        scanScripts();

    for (auto && pair : m_scripts)
    {
        pair.second.load (m_scriptsFolderPath + '/' + pair.first);
    }
}

Script ScriptLoader::getScript (std::string scriptName)
{
    if (scriptName.find (".eqs") == std::string::npos)
        scriptName += ".eqs";

    if (!hasScript (scriptName))
        return Script();

    Script script = m_scripts[scriptName];
    if (!script.m_loaded)
        script.load (m_scriptsFolderPath + '/' + scriptName);

    return script;
}
