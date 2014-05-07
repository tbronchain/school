#ifndef MODULE_H_
# define MODULE_H_

#include "LibManager.h"
#include "IModule.hpp"
#include "IConf.hpp"

class				Module
{
public:
	typedef	void (*LOAD)(zia::api::IConf& conf, zia::api::ILog& log);
	typedef zia::api::IModule* (*NEW)(std::list<zia::api::HttpStep::Pair>& steps,
                                   zia::api::IConnection& connection,
                                   zia::api::IConf& conf);
	typedef void (*UNLOAD)(zia::api::ILog& log);

	// CONSTRUCTEUR/DESTRCUTEUR
	Module();
	~Module();

	// METHODES PUBLIQUES
	IADDR			getLoadAddr();
	IADDR			getModuleNewAddr();
	IADDR			getUnloadAddr();

        void			setLoadAddr(const IADDR&);
        void			setModuleNew(const IADDR&);
        void			setUnLoadAddr(const IADDR&);

	Module::LOAD&		getLoadMethod();
	Module::NEW&		getNewMethod();
	Module::UNLOAD&		getUnloadMethod();

        bool			isLoadMethodSet();
        bool			isNewMethodSet();
        bool			isUnLoadMethodSet();

        void			setLoadMethod(const Module::LOAD& load);
        void			setNewMethod(const Module::NEW& newMethod);
        void			setUnLoadMethod(const Module::UNLOAD& unload);

private:

	// ADDR METHODES
        IADDR			loadAddr_;
        IADDR			moduleNewAddr_;
        IADDR			unloadAddr_;

	// METHODES DU MODULE
        LOAD			mL_;
        NEW			nM_;
        UNLOAD			uL_;
};

#endif //!MODULE_H_
