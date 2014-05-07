#ifndef UNIXFILESYSTEM_H_
# define UNIXFILESYSTEM_H_

#include <dirent.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include "IFileSystem.h"

class							UnixFileSystem : public IFileSystem
{
public:
	std::list<std::string>		FSListDir(const std::string& path) const;
};

#endif // !UNIXFILESYSTEM_H_
