#ifndef SERVER_H_
# define SERVER_H_

# include <map>
# include "ObjectPool.hpp"
# include "XMLparse.h"
# include "Mutex.h"
# include "Client.h"
# include "DescriptorWatcher.h"
# include "ConditionVariable.h"
# include "IPC.h"
# include "Socket.h"
# include "Parser.h"
# include "Module.h"
# include "ModuleManager.h"
# include "httpExec.h"
# include "Url.h"

# ifdef _WIN32
#  define CLOSESOCKET closesocket
# else
#  define CLOSESOCKET close
# endif

class Controller;


class							Server
{
public:
    Server(Controller&, int, int, XMLparser);
    ~Server();

    void						run();
    void						addNewClient(Socket*);
    int							getClientMapSize();
    void						orderSleepSync();
    void                                                orderAwakeSync();
    ABSIPC&                                             getIpc();
    moduleManager&                                  	getModuleManager();
    zia::api::IConf&                            	getConf();
    void						execPhpPost(Client *c, std::string);
    
private:
    void                                                releaseClientToObjectPool(Client *);
    void						loadModules();
    void						cleanServer();
    void						addOneToClientMapSize();
    void						removeClientFromMapContextLocked(std::map<int , Client *>::iterator &);
    void						removeOneFromClientMapSize();
    void						buildDescriptorWatcher();
    void						descriptorWatch();
    bool						parseHeader(Client*);
    void						readAndWrite();
    void						removeClient();
    void						treatIPC();
    std::map<int, Client *>                             clientMap_;
    ObjectPool<Client>                                  clientPool_;
    std::string                         		elRetrivorDiElBody(Client*);
    ABSMUTEX                                		clientMapMutex_;
    ABSMUTEX                            		clientMapSizeMutex_;
    ABSCONDITION                        		syncCondition;
    ABSIPC						ipc;
    int							clientMapSize_;
    Controller&                         		controller_;
    DescriptorWatcher                           	descriptorWatcher_;
    XMLparser                           		serverConf_;
    parser						parser_;
    url							url_;
    bool						stopForce_;
    bool						stopClean_;
    int							timeout_;
    moduleManager                       		moduleManager_;
    zia::api::ILog                      		*log_;
    httpExec                            		exec_;
};

#endif // SERVER_H_
