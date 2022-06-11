#include <fstream>
#include <queue>
#include "App.h"

std::string removeQuotes (std::string str)
{
    if (str.size() < 2)
        return str;

    if (str[0] == '"' && str[str.size() - 1] == '"')
        return str.substr(1, str.size() - 2);

    return str;
}

int main (int argc, char *argv[])
{
    App app;

    std::queue<std::string> argQueue;
    for (int i = 1; i < argc; i++)
    {
        argQueue.emplace (argv[i]);
    }

    while (!argQueue.empty())
    {
        if (!app.runCommand (argQueue))
            return 1;
    }

    return 0;
}
