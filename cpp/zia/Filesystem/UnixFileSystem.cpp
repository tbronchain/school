#include <iostream>
#include <list>
#include "UnixFileSystem.h"

std::list<std::string>		UnixFileSystem::FSListDir(const std::string& path) const
{
	int						fcount = 0;
	std::list<std::string>		ret;
	struct dirent			**filelist = NULL;

	fcount = scandir(path.c_str(), &filelist, 0, alphasort);
	for(int i = 0; i < fcount; i++)
	{
		ret.push_back(filelist[i]->d_name);
	}
	return (ret);
}
