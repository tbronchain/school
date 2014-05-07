#ifndef IFILESYSTEM_H_
# define IFILESYSTEM_H_

#include <iostream>
#include <list>
#include <string>

class									IFileSystem
{
public:
	virtual								~IFileSystem(void) {};
	virtual	std::list<std::string>		FSListDir(const std::string& path) const = 0;
};

#ifdef _WIN32
# include "WindowsFileSystem.h"
#else
# include "UnixFileSystem.h"
#endif

#endif // !IFILESYSTEM_H_
