#ifndef LIBMANAGER_H_
# define LIBMANAGER_H_

//#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <string>

#ifdef _WIN32
//#define WIN32_LEAN_AND_MEAN
  # include <WinSock2.h>
  # include <Windows.h>
typedef HMODULE	IHANDLE;
typedef FARPROC	IADDR;
#else
typedef void*	IHANDLE;
typedef void*	IADDR;
#endif

class					LibManager
{
public:
	virtual				~LibManager() {}
	virtual IHANDLE		openLib(const std::string& filename) = 0;
	virtual bool		closeLib(IHANDLE handle) = 0;
	virtual	IADDR		loadFunction(IHANDLE handle, const std::string& symbol) = 0;
};

#ifdef _WIN32
# include "LibManagerWindows.h"
#  define ABSLM LibManagerWindows
#else
# include "LibManagerUnix.h"
#  define ABSLM LibManagerUnix
#endif

#endif //!ILIBMANAGER_H_
