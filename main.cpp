#include <fstream>
#include "App.h"

int main (int argc, char *argv[])
{
    App app;

    if (argc == 1)
    {
        app.runCommand("off");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        app.runCommand(argv[i]);
    }

    return 0;
}
