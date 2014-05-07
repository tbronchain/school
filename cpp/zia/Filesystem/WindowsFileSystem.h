#ifndef WINDOWSFILESYSTEM_H_
# define WINDOWSFILESYSTEM_H_

#include "IFileSystem.h"

class							WindowsFileSystem : public IFileSystem
{
public:
	std::list<std::string>		FSListDir(const std::string& path) const;
};

#endif // !WINDOWSFILESYSTEM_H_