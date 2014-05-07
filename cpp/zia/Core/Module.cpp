#include "Module.h"

Module::Module()
{

}

Module::~Module()
{

}

IADDR			Module::getLoadAddr()
{
	return (this->loadAddr_);
}

IADDR			Module::getModuleNewAddr()
{
	return (this->moduleNewAddr_);
}

IADDR			Module::getUnloadAddr()
{
	return (this->unloadAddr_);
}

void		Module::setLoadAddr(const IADDR& load)
{
	this->loadAddr_ = load;
}

void		Module::setModuleNew(const IADDR& modNew)
{
		this->moduleNewAddr_ = modNew;
}

void		Module::setUnLoadAddr(const IADDR& unload)
{
	this->unloadAddr_ = unload;
}

void		Module::setLoadMethod(const Module::LOAD& load)
{
	this->mL_ = load;
}

void		Module::setNewMethod(const Module::NEW& newMethod)
{
	this->nM_ = newMethod;
}

void		Module::setUnLoadMethod(const Module::UNLOAD& unload)
{
	this->uL_ = unload;
}

Module::LOAD&		Module::getLoadMethod()
{
	return (this->mL_);
}

Module::NEW&		Module::getNewMethod()
{
	return (this->nM_);
}

Module::UNLOAD&		Module::getUnloadMethod()
{
	return (this->uL_);
}

bool		Module::isLoadMethodSet()
{
	if (this->loadAddr_ == NULL)
		return (false);
	return (true);
}

bool		Module::isNewMethodSet()
{
	if (this->moduleNewAddr_ == NULL)
		return (false);
	return (true);
}

bool		Module::isUnLoadMethodSet()
{
	if (this->unloadAddr_ == NULL)
		return (false);
	return (true);
}
