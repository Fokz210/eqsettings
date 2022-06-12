cmake_minimum_required(VERSION 3.22)
project(EQSettings)

set(CMAKE_CXX_STANDARD 17)


add_executable(EQSettings main.cpp Configurator.cpp Configurator.h PluginConfig.cpp PluginConfig.h App.cpp App.h ScriptLoader.cpp ScriptLoader.h Script.cpp Script.h project.h)
target_link_libraries(EQSettings -static-libgcc -static-libstdc++ -static)