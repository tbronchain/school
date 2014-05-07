#include "IConf.hpp"
#include "Error.hpp"
#include "Log.h"
#include "ModuleManager.h"

moduleManager::moduleManager()
{
  #ifdef _WIN32
  this->unix_ = false;
#else
  this->unix_ = true;
#endif
	this->lm_ = new ABSLM();
}

moduleManager::~moduleManager()
{
	this->modules_.clear();
}

void											moduleManager::retrieveModulesFunctions(zia::api::IConf&)
{
	std::map<std::string, Module*>::iterator	listIt;

	for (listIt = this->modules_.begin(); listIt != this->modules_.end(); ++listIt)
	{

	  if (listIt->second->getLoadAddr() != NULL)
	    listIt->second->setLoadMethod(reinterpret_cast<const Module::LOAD>(listIt->second->getLoadAddr()));

	  if (listIt->second->getModuleNewAddr() != NULL)
	    listIt->second->setNewMethod(reinterpret_cast<const Module::NEW>(listIt->second->getModuleNewAddr()));
	  else
	    {
			std::map<std::string, Module*>::iterator erase = listIt;
			this->modules_.erase(erase);
			return ;
	    }
	  if (listIt->second->getUnloadAddr() != NULL)
	    listIt->second->setUnLoadMethod(reinterpret_cast<const Module::UNLOAD>(listIt->second->getUnloadAddr()));
	}
}

void									moduleManager::loadModules(zia::api::IConf& conf, zia::api::ILog *log)
{
	for (std::list< std::string >::iterator	listIt = conf["modules"].mList.begin();
		 listIt != conf["modules"].mList.end();)
	{
		Module *m = new Module();
		IHANDLE h;
		bool ext = false;

		if (this->unix_)
			ext = checkExtensionLib(*listIt, ".so");
		else
			ext = checkExtensionLib(*listIt, ".dll");
		

	h = this->lm_->openLib(*listIt);
		if (ext == true && h != NULL)
		{
			m->setLoadAddr(this->lm_->loadFunction(h, "dll_load"));
			m->setModuleNew(this->lm_->loadFunction(h, "module_new"));
			m->setUnLoadAddr(this->lm_->loadFunction(h, "dll_unload"));
			this->modules_.insert(std::pair< std::string, Module* >(*listIt, m));
			listIt++;
		}
		else
		{
			delete m;
			*log << zia::api::LOG_ERR << "Exception: cant find module " << *listIt << std::endl;
			++listIt;
		}
	}
	*log << zia::api::LOG_INFO << " Server loaded modules successfully" << std::endl;
}

void				moduleManager::fillModsCallback(zia::api::IConf& conf, std::list< zia::api::HttpStep::Pair>& step, zia::api::IConnection* socket)
{
	Log				log;
	std::map<std::string, Module*>::const_iterator	listIt;
	int i = 0;
	for (listIt = this->modules_.begin(); listIt != this->modules_.end(); ++listIt)
	{
		if (listIt->second->isLoadMethodSet())
			listIt->second->getLoadMethod()(conf, log);
		if (listIt->second->isNewMethodSet())
			listIt->second->getNewMethod()(step, *socket, conf);
		if (listIt->second->isUnLoadMethodSet())
			listIt->second->getUnloadMethod()(log);
		i++;
	}
}

bool		moduleManager::checkExtensionLib(const std::string& item, const char* ext)
{
		if (item.find(ext) != std::string::npos)
		      return (true);
		return (false);
}


void		moduleManager::unloadModules()
{

}

const std::map<std::string, Module*>		moduleManager::getModules()
{
	return (this->modules_);
}

