//
// Created by Ivan on 5/28/2022.
//

#ifndef EQSETTINGS_PLUGINCONFIG_H
#define EQSETTINGS_PLUGINCONFIG_H


#include <string>
#include <vector>

class PluginConfig
{
private:
    std::string m_type;
    std::string m_params;
    bool m_active;

public:
    PluginConfig(const std::string & pluginLine);
    PluginConfig();

    void setType(const std::string & type);
    void setParams(std::string & params);
    void setActive(bool active);
    bool getActive() const;

    std::string getType() const;
    std::string getParams() const;
    bool isActive() const;

    void loadConfig(const std::string & configLine);
    void printConfig(std::ostream & out = std::cout) const;
};


#endif //EQSETTINGS_PLUGINCONFIG_H
