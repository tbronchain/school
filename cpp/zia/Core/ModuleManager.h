#ifndef MODULEMANAGER_H_
# define MODULEMANAGER_H_

#include "IConf.hpp"
#include "Log.h"
#include "Module.h"
#include "LibManager.h"
#include "IModule.hpp"

class											moduleManager
{
public:
    moduleManager();
    ~moduleManager();
    void										loadModules(zia::api::IConf&, zia::api::ILog*);
    void										retrieveModulesFunctions(zia::api::IConf&);
    void										fillModsCallback(zia::api::IConf&, std::list< zia::api::HttpStep::Pair >&, zia::api::IConnection*);
    //	void										fillModsCallback(zia::api::IConf&, zia::api::IConnection*);
    void										unloadModules();
    bool										checkExtensionLib(const std::string&, const char*);
    void										execModuleAtStep();
    const std::map<std::string, Module*>                                                getModules();

private:
    std::map<std::string, Module*>                                              	modules_;
    ABSLM*										lm_;
    bool                                                                                unix_;
};

#endif //!MODULEMANAGER_H_
