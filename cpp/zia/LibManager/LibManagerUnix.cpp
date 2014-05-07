#include "LibManagerUnix.h"

LibManagerUnix::LibManagerUnix(void)
{

}

LibManagerUnix::~LibManagerUnix(void)
{

}

IHANDLE		LibManagerUnix::openLib(const std::string& filename)
{
	void		*module;

	std::string	name = "./Visual/zia/";

	name += filename;
	module = dlopen(name.c_str(), RTLD_LAZY);
	return (static_cast<IHANDLE>(module));
}

bool			LibManagerUnix::closeLib(IHANDLE handle)
{
	int			res;

	res = dlclose(handle);
	if (res == 0)
		return true;
	return false;
}

IADDR		LibManagerUnix::loadFunction(IHANDLE handle, const std::string& symbol)
{
	void		*addr;

	addr = dlsym(handle, symbol.c_str());
	return (addr);
}
