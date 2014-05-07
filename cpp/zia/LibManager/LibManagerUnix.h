#ifndef LIBMANAGERUNIX_H_
# define LIBMANAGERUNIX_H_

#include <dlfcn.h>
#include "LibManager.h"

class	LibManagerUnix : virtual public LibManager
{
public:
	LibManagerUnix();
	~LibManagerUnix();
	IHANDLE		openLib(const std::string& filename);
	bool		closeLib(IHANDLE handle);
	IADDR		loadFunction(IHANDLE handle, const std::string& symbol);
};

#endif //!LIBMANAGERUNIX_H_