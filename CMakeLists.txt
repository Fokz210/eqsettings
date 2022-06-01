cmake_minimum_required(VERSION 3.22)
project(EQSettings)

set(CMAKE_CXX_STANDARD 14)


add_executable(EQSettings main.cpp Configurator.cpp Configurator.h PluginConfig.cpp PluginConfig.h App.cpp App.h)
target_link_libraries(EQSettings -static-libgcc -static-libstdc++ -static)