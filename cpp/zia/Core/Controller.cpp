//

#ifdef _WIN32
# include <WinSock2.h>
#endif // _WIN32
#include <sstream>
#include "IConf.hpp"
#include "XMLparse.h"
#include "Socket.h"
#include "Controller.h"

Controller::Controller(unsigned int lim_fd) :
        ipc(W_IPC),
        lim_fd_(lim_fd),
        descriptorWatcher_(1024),
        controllerRun_(true),
        uiRun_(true)
{
    // Load config et modules
    this->loadConfig();
    // socket principale
    Socket* s = new ABSSOCKET(atoi(this->serverConf_.getConf()["port"].mValue.c_str()));

    s->info()["connection"]["port"].mValue = this->serverConf_.getConf()["port"];
    s->bindSocket();
    s->listenSocket();
    this->serverSockets_[s->getSocket()] = s;

    // socket SSL si les valeurs du fichier de conf sont sets
    if (!this->serverConf_.getConf()["ssl-module"].mValue.empty() && !this->serverConf_.getConf()["ssl-port"].mValue.empty())
    {
        std::ostringstream	oss;
        Socket*				ssl = new ABSSOCKET(atoi(this->serverConf_.getConf()["ssl-port"].mValue.c_str()));
        ssl->info()["connection"]["port"] = this->serverConf_.getConf()["ssl-port"];
        oss << ssl->getSocket();
        std::string result = oss.str();
        ssl->info()["connection"]["socket"] = result;
        ssl->bindSocket();
        ssl->listenSocket();
        this->serverSockets_[ssl->getSocket()] = ssl;
    }

}

Controller::~Controller()
{
    /*   while (this->serverSockets_.empty())
    {
        if (this->serverSockets_.back())
            delete this->serverSockets_.back();
        this->serverSockets_.pop_back();
    }
    */
    //delete serverSocket_;

    while (this->serverSockets_.begin() != this->serverSockets_.end())
    {
        delete this->serverSockets_.begin()->second;
        this->serverSockets_.erase(this->serverSockets_.begin());
    }
}

//Socket*			Controller::getServerSocket()
//{
//    return this->serverSocket_;
//}

std::map<int ,Socket*>&	Controller::getServerSocket()
{
    return this->serverSockets_;
}

void			Controller::loadConfig()
{
    std::string	conf_filename = CONF_FILENAME;

    // si on ne peux pas lire le fichier de config on le remplit avec les valeurs par default
    if (this->serverConf_.readConfigFile(conf_filename) == false)
        this->serverConf_.putDefaultValues();
}

void			Controller::runServer()
{

    this->shellUiThread = new Thread<Controller>(*this, &Controller::shellUi);
    this->playServers();
    while (this->controllerRun_)
        this->run();
    this->shellUiThread->join();
}

void			Controller::addNewClient(Socket* s)
{
    if (this->serverMap_.empty())
        return ;

    int smaller = this->serverMap_.begin()->first->getClientMapSize();
    Server* associatedServer = this->serverMap_.begin()->first;

    int			i = 0;
    int			iServSmallest = 0; //dbgInfo u can delete

    for (std::map<Server*, Thread<Server> *>::iterator it = this->serverMap_.begin();
    it != this->serverMap_.end();
    ++it, ++i)
    {
        if (it->first->getClientMapSize() < smaller)
        {
            smaller = it->first->getClientMapSize();;
            associatedServer = it->first;
            iServSmallest = i;
        }
    }

    if (!associatedServer)
    {
        std::cerr << "FATAL error, no server available" << std::endl;
        return ;
    }
    else
    {
        //std::cout << smaller << " Client on Server " << iServSmallest  << std::endl;
    }
    associatedServer->orderSleepSync();
    //Socket* clientSocket = this->serverSocket_->acceptSocket();
    Socket* clientSocket = s->acceptSocket();
    if (clientSocket)
    {
        clientSocket->info() = s->info();
        associatedServer->addNewClient(clientSocket);
    }
    associatedServer->orderAwakeSync();
}


ABSCONDITION& Controller::getSyncCondition()
{
    return this->syncCondition_;
}

ABSMUTEX& Controller::getSyncMutex()
{
    return this->syncMutex_;
}


void            Controller::commandStopClean()
{
    this->ipc.write(IPC::STOP_CLEAN);
    this->uiRun_ = false;
}

void            Controller::commandStopForce()
{
    this->ipc.write(IPC::STOP_FORCE);
    this->uiRun_ = false;
}

void            Controller::commandReloadClean()
{
    this->ipc.write(IPC::RELOAD_CLEAN);
}

void            Controller::commandReloadForce()
{
    this->ipc.write(IPC::RELOAD_FORCE);
}


void            Controller::shellUi()
{
    this->_parsingCommandMap["stop-clean"] =  &Controller::commandStopClean;
    this->_parsingCommandMap["stop-force"] =  &Controller::commandStopForce;
    this->_parsingCommandMap["reload-force"] =  &Controller::commandReloadForce;
    this->_parsingCommandMap["reload-clean"] =  &Controller::commandReloadClean;
    while (this->uiRun_)
    {

        std::cout << "$zia-bronch_t>";
        std::string query = "";
        std::cin >> query;
        if (this->_parsingCommandMap.find(query) != this->_parsingCommandMap.end())
            (this->*(this->_parsingCommandMap[query]))();
    }
}





zia::api::IConf&		Controller::getServerConf()
{
    return (this->serverConf_.getConf());
}

void		Controller::run()
{
    DescriptorConf cf;
    for (std::map<int, Socket * >::iterator it = this->serverSockets_.begin();
    it != this->serverSockets_.end();
    ++it)
    {
        cf.setRead();
        cf.setError();
        cf.setDescriptor((*it).second->getSocket());
        this->descriptorWatcher_.getAskDeque().push_back(cf);
    }

    cf.setRead();
    cf.setError();
    cf.setDescriptor(this->ipc.getReadFd());
    this->descriptorWatcher_.getAskDeque().push_back(cf);
    this->descriptorWatcher_.watch();
    std::map<int, Socket* >::iterator itSearch;
    while (!this->descriptorWatcher_.getReadyDeque().empty())
    {
        if ((!this->descriptorWatcher_.getReadyDeque().front().readyError()) && this->descriptorWatcher_.getReadyDeque().front().readyRead())
        {
            if (this->descriptorWatcher_.getReadyDeque().front().getDescriptor() == (this->ipc.getReadFd()))
            {

                IPC::CMD ret = this->ipc.read();
                if (ret == IPC::RELOAD_CLEAN ||
                    ret == IPC::RELOAD_FORCE ||
                    ret == IPC::STOP_CLEAN ||
                    ret == IPC::STOP_FORCE)
                {
                    this->stopServers(ret);
                }
                while (!this->descriptorWatcher_.getReadyDeque().empty())
                {
                    this->descriptorWatcher_.getReadyDeque().pop_front();
                }
                break;
            }
            else if ((itSearch = this->serverSockets_.find(this->descriptorWatcher_.getReadyDeque().front().getDescriptor()))
                != this->serverSockets_.end())
                {
                this->addNewClient((*itSearch).second);
            }
        }
        this->descriptorWatcher_.getReadyDeque().pop_front();
    }
}


void Controller::stopServers(IPC::CMD cmd)
{
    std::map<Server*, Thread<Server>* >::iterator it = this->serverMap_.begin();
    while (it != this->serverMap_.end())
    {
        it->first->getIpc().write(cmd);
        it->second->join();
        delete it->second;
        delete it->first;
        this->serverMap_.erase(it++);
    }
    if (cmd == IPC::RELOAD_FORCE || cmd == IPC::RELOAD_CLEAN)
    {
        this->playServers();
    }
    else
        this->controllerRun_ = false;
}

void Controller::playServers()
{
    //reloadconf
    int p  = W_IPC + 1;
    for (int i = 0 ; i < atoi(this->serverConf_.getConf()["thread-number"].mValue.c_str()) ; i++)
    {
        Server* server = new Server(*this, this->lim_fd_, p + i, this->serverConf_);
        Thread<Server>* thread = new Thread<Server>(*server, &Server::run);
        this->serverMap_[server] = thread;
    }
}
