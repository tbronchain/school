#ifndef LIBMANAGERWINDOWS_H_
# define LIBMANAGERWINDOWS_H_

#include "LibManager.h"

class	LibManagerWindows : virtual public LibManager
{
public:
	LibManagerWindows();
	~LibManagerWindows();
	IHANDLE		openLib(const std::string& filename);
	bool		closeLib(IHANDLE handle);
	IADDR		loadFunction(IHANDLE handle, const std::string& symbol);
};

#endif //!LIBMANAGERWINDOWS_H_