#ifndef CONTROLLER_H_
# define CONTROLLER_H_

# include <map>
# include <deque>

# include "Thread.hpp"
# include "Server.h"
# include "IPC.h"

# define SERVER_NB		1

# define CONF_FILENAME "zia-config.xml"
# define SERVER_SOCK            8080
# define MAX_CON		40960
# define W_IPC			22140

typedef void (Controller::*pmethod)();

class Controller
{
public:
    Controller(unsigned int);
    ~Controller();

    void					runServer();
    void					stopServers();
    void					run();
    void					addNewClient(Socket*);
    void					loadConfig();
    std::map<int, Socket*>&            		getServerSocket();
    ABSCONDITION&             			getSyncCondition();
    ABSMUTEX&                                   getSyncMutex();
    zia::api::IConf&                            getServerConf();


private:
    void					stopServers(IPC::CMD);
    void					pauseServers(IPC::CMD);
    void                                        playServers();
    void                                        shellUi();
    void                                        commandStopClean();
    void                                        commandStopForce();
    void                                        commandReloadClean();
    void                                        commandReloadForce();

    ABSCONDITION                                syncCondition_;
    ABSMUTEX                                    syncMutex_;
    ABSIPC                                      ipc;
    unsigned int				lim_fd_;
    DescriptorWatcher				descriptorWatcher_;
    std::map<Server*, Thread<Server>* >         serverMap_;
    Thread<Controller>*                         shellUiThread;
    Socket*					serverSocket_;

    std::map<int, Socket*>                      serverSockets_;
    std::map<std::string, pmethod>              _parsingCommandMap;
    bool                                        controllerRun_;
    bool                                        uiRun_;

    XMLparser					serverConf_;

};

#endif // CONTROLLER_H_
