#include <fstream>
#include <queue>
#include <list>
#include "App.h"
#include "ScriptLoader.h"

std::string removeQuotes (std::string str)
{
    if (str.size() < 2)
        return str;

    if (str[0] == '"' && str[str.size() - 1] == '"')
        return str.substr(1, str.size() - 2);

    return str;
}


int main()
{
    ScriptLoader sl("scripts");
    sl.scanScripts();
    sl.preload();

    std::list<std::string> script = sl.getScript ("test1").m_script;

    for (auto && el : script)
        std::cout << el << " ";
}
