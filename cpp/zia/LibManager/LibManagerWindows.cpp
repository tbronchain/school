#include "LibManagerWindows.h"

LibManagerWindows::LibManagerWindows()
{

}

LibManagerWindows::~LibManagerWindows()
{

}

IHANDLE		LibManagerWindows::openLib(const std::string& filename)
{
	HMODULE		module;

	module = LoadLibrary(filename.c_str());
	return (static_cast<IHANDLE>(module));
}

bool		LibManagerWindows::closeLib(IHANDLE handle)
{
	BOOL	res;

	res = FreeLibrary(handle);
	if (res == FALSE)
		return false;
	return true;
}

IADDR		LibManagerWindows::loadFunction(IHANDLE handle, const std::string& symbol)
{
	FARPROC	addr;

	addr = GetProcAddress(handle, symbol.c_str());
	return (static_cast<IADDR>(addr));
}