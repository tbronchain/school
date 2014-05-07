
/*Open Unix not abstracted if committed bronch_t will chie dans le pathé*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include "Server.h"
#include "Controller.h"

Server::Server(Controller& ctrl, int descMax,  int nbPiPc , XMLparser serverConf) :
        ipc(nbPiPc),
        clientMapSize_(0),
        controller_(ctrl),
        descriptorWatcher_(descMax),
        serverConf_(serverConf),
        stopForce_(false),
        stopClean_(false),
        timeout_(-1),
	log_(new Log())
{
  this->loadModules();
}

Server::~Server()
{
}

void			Server::loadModules()
{
	
	// loading des adresses des modules
	this->moduleManager_.loadModules(this->serverConf_.getConf(), this->log_);

	// recuperation des methodes des modules (dll_load module_new dll_unload)
	this->moduleManager_.retrieveModulesFunctions(this->serverConf_.getConf());

	this->log_->flush();
}

void Server::run()
{
    while (true)
    {
        this->syncCondition.SleepCondHandshakedSlave(this->controller_.getSyncCondition(), this->controller_.getSyncMutex());
        if ((this->stopForce_) || (this->stopClean_ && this->getClientMapSize() == 0))
        {
            this->cleanServer();
			*this->log_ << zia::api::LOG_INFO << " Server down" << std::endl;
			this->log_->flush();
            break;
        }
        this->buildDescriptorWatcher();
        this->descriptorWatch();
    }
}

std::string Server::elRetrivorDiElBody(Client *cli)
{
  std::string body = cli->getBody();
  return (body);
}
void Server::treatIPC()
{
    IPC::CMD cmd = this->ipc.read();
    if (cmd == IPC::STOP_FORCE || cmd == IPC::RELOAD_FORCE)
    {
        this->stopForce_ = true;
    }
    if (cmd == IPC::STOP_CLEAN || cmd == IPC::RELOAD_CLEAN)
    {
		*this->log_ << zia::api::LOG_INFO << " Reload succesfull" << std::endl;
		this->log_->flush();
        this->stopClean_ = true;
    }
}

void Server::cleanServer()
{

  //FUCK
    this->clientMapMutex_.lock();
    std::map<int , Client *>::iterator it  = this->clientMap_.begin();
    while (it != this->clientMap_.end())
    {
      this->releaseClientToObjectPool(it->second);
      it++;
    }
    this->clientMapMutex_.unlock();
}


void Server::addNewClient(Socket* clientSocket)
{
    this->clientMapMutex_.lock();

    Client *cl = this->clientPool_.getObj();
   if (cl == 0)
    {
		cl = new Client();
        this->clientPool_.putNewObjInUsedMap(cl);
    }
    cl->initClient(clientSocket, this);
    this->clientMap_[clientSocket->getSocket()] = cl;
    this->clientMapMutex_.unlock();
    this->addOneToClientMapSize();
}

void Server::releaseClientToObjectPool(Client *cli)
{
    cli->resetClient();
    this->clientPool_.releaseObj(cli);
}

void Server::orderSleepSync()
{
    this->syncCondition.orderSleepCondHandshaked(this->controller_.getSyncCondition(), this->controller_.getSyncMutex());
}

void Server::orderAwakeSync()
{
    this->syncCondition.WakeCond(this->controller_.getSyncCondition(), this->controller_.getSyncMutex());
}

void Server::addOneToClientMapSize()
{
    this->clientMapSizeMutex_.lock();
    ++this->clientMapSize_;
    this->clientMapSizeMutex_.unlock();
}

void Server::removeOneFromClientMapSize()
{
    this->clientMapSizeMutex_.lock();
    --this->clientMapSize_;
    this->clientMapSizeMutex_.unlock();
}

ABSIPC& Server::getIpc()
{
    return this->ipc;
}

int Server::getClientMapSize()
{
    this->clientMapSizeMutex_.lock();
    int ret = this->clientMapSize_;
    this->clientMapSizeMutex_.unlock();
    return ret;
}

void Server::buildDescriptorWatcher()
{
    if (!this->stopClean_)
    {
        for (std::map<int, Socket*>::iterator it = this->controller_.getServerSocket().begin();
        it != this->controller_.getServerSocket().end();
        ++it)
        {
            DescriptorConf cf;
            cf.setRead();
            cf.setError();
            cf.setDescriptor(it->second->getSocket());
            this->descriptorWatcher_.getAskDeque().push_back(cf);
        }
    }

    this->clientMapMutex_.lock();

    this->timeout_ = -1;
    for (std::map<int, Client *>::iterator it = this->clientMap_.begin();
    it != this->clientMap_.end();)
    {
        if (it->second->isPersistent() == true)
        {
            if (it->second->isEnd() == true)
            {
				releaseClientToObjectPool(it->second);
                this->clientMap_.erase(it++);
                this->removeOneFromClientMapSize();
                //it = this->clientMap_.begin();
                continue ;
            }
            else
            {
                this->timeout_ = it->second->getTimeout(this->timeout_);
            }
        }
        DescriptorConf cf;
        cf.setRead();
        cf.setError();
        cf.setDescriptor(it->first);
        if (it->second->isWData())
            cf.setWrite();
        this->descriptorWatcher_.getAskDeque().push_back(cf);
        ++it;
    }

    this->clientMapMutex_.unlock();

    // IPC
    DescriptorConf cf;
    cf.setRead();
    cf.setError();
    cf.setDescriptor(this->ipc.getReadFd());
    this->descriptorWatcher_.getAskDeque().push_back(cf);
}


void Server::removeClientFromMapContextLocked(std::map<int , Client *>::iterator &it)
{
    //it->second->resetClient();
	//delete it->second;

    releaseClientToObjectPool(it->second);
    this->clientMap_.erase(it);
    it = this->clientMap_.end();
    this->removeOneFromClientMapSize();
}

void Server::descriptorWatch()
{
    this->descriptorWatcher_.watch(this->timeout_);
    this->clientMapMutex_.lock();

    while (!this->descriptorWatcher_.getReadyDeque().empty())
    {
        std::map<int , Client *>::iterator itFind = this->clientMap_.find(this->descriptorWatcher_.getReadyDeque().front().getDescriptor());
        if (this->descriptorWatcher_.getReadyDeque().front().readyError() && itFind != this->clientMap_.end())
            this->removeClientFromMapContextLocked(itFind);
        else
		{
			if (this->descriptorWatcher_.getReadyDeque().front().readyRead() &&
				itFind != this->clientMap_.end())
			{
				int rd = itFind->second->readData();
				if (rd > 0)
				{
					itFind->second->resetEnd();
					if (itFind->second->isBody_ == true && itFind->second->getMessage()->http()["method"] == "PUT")
					{
						// traiter la req
						itFind->second->isBody_ = false; // tmp
					}
					else if (itFind->second->isRData())
					{
						/*
						* API STEP_IN_POST
						*/
						// READ DANS LE ASTREAM
						/*if (itFind->second->checkIfModAtStep(zia::api::STEP_IN_POST) == true)
							itFind->second->execMethodAtStep(zia::api::STEP_IN_POST, itFind->second->getInput());
							*/

						/*
						* API PARSER PRE
						*/
						if (itFind->second->checkIfModAtStep(zia::api::STEP_PARSER_PRE) == true)
							itFind->second->execMethodAtStep(zia::api::STEP_PARSER_PRE, itFind->second->getInput());


						/*
						* API STEP PARSER
						*/
						bool header = false;
						if (itFind->second->checkIfModAtStep(zia::api::STEP_PARSER) == true)
							itFind->second->execMethodAtStep(zia::api::STEP_PARSER, itFind->second->getInput());
						else
						{
							if (this->parseHeader(itFind->second) == false)
							{
								header = false;
								itFind->second->isPersistent(false);
							}
							else
							{
								header = true;
								if (itFind->second->isPersistent() == true)
								{
									if (itFind->second->getMessage()->http()["http"].has("Connection") == true)
									{
										if (itFind->second->getMessage()->http()["http"]["Connection"].mValue == "close")
											itFind->second->isPersistent(false);
									}
								}
							}
							//
						}

						/*
						* API STEP PARSER POST
						*/
						if (itFind->second->checkIfModAtStep(zia::api::STEP_PARSER_POST) == true && header)
							itFind->second->execMethodAtStep(zia::api::STEP_PARSER_POST, itFind->second->getInput());

						//enlever par enzo pour impl CB
						//--->itFind->second->delData();
						// STOCKER CONTENU

						if (header)
						{
							const char* const meth = itFind->second->getMessage()->http()["method"].mValue.c_str();
							if (this->exec_.getMap().find(meth) != this->exec_.getMap().end())
							{

								(this->exec_.*this->exec_.getMap()[meth])(*(itFind->second));
								if (itFind->second->getMessage()->http()["method"] == "POST")
								{
									std::string body = this->elRetrivorDiElBody(itFind->second);
									this->execPhpPost(itFind->second, body);
								}
							}
							else
							{
								this->exec_.setHeader(*(itFind->second), "400", "BAD REQUEST", true);
								itFind->second->setData(EOL);
								itFind->second->setData("400: BAD REQUEST");
								itFind->second->setData(EOL);
							}
						}

						if (itFind->second->isPersistent() == false)
						  {
						    itFind->second->getMessage()->http().clear();
							itFind->second->setData(0);
						  }
					}
				}
				else if (rd < 0)
				{
					this->removeClientFromMapContextLocked(itFind);
				}
			}
			if (this->descriptorWatcher_.getReadyDeque().front().readyWrite() && itFind != this->clientMap_.end())
			{
				int wr = itFind->second->writeData();
				if (wr > 0)
				{
					if (itFind->second->isPersistent())
						itFind->second->resetEnd();
				}
				else if (wr < 0)
				{
					this->removeClientFromMapContextLocked(itFind);
				}
			}
		}
		if (this->descriptorWatcher_.getReadyDeque().front().getDescriptor() ==
			this->ipc.getReadFd() &&
			this->descriptorWatcher_.getReadyDeque().front().readyRead())
		{
			this->treatIPC();
		}
		this->descriptorWatcher_.getReadyDeque().pop_front();
	}
	this->clientMapMutex_.unlock();
}

void					Server::execPhpPost(Client *c, std::string body)
{
	zia::api::AStream	*output = c->getOutput();
	char*				buff = new char[4096];
	std::string			res;
	
	memset(buff, 0, 4096);

	if (c->checkIfModAtStep(zia::api::STEP_EXEC) == true)
		{
		  std::cout << "LLLLLL " <<  body << std::endl;
			c->getInput()->write(body.c_str(), body.size());
			output = c->execMethodAtStep(zia::api::STEP_EXEC, c->getInput());
			while (output->canRead())
			{
			  output->read(buff, 4096);
			  if (strcmp(buff, "") == 0)
			    output->drop();
			  res += buff;
			  memset(buff, 0, 4096);
			}
			output->drop();
			c->setData(res);
			c->setData(EOL);
		}
}

bool				Server::parseHeader(Client *c)
{
	zia::api::IMessage*	msg;
	std::string			header;

	msg = c->getMessage();

    header = c->getHeader();
    header += '\0';
    try
    {
      this->parser_.parse(header, msg->http());
      this->url_.parse(msg->http());
    }
    catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

moduleManager&		Server::getModuleManager()
{
	return this->moduleManager_;
}

zia::api::IConf& Server::getConf()
{
	return this->serverConf_.getConf();
}
