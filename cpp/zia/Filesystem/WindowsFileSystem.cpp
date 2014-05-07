#include <Windows.h>
#include "WindowsFileSystem.h"

std::list<std::string>		WindowsFileSystem::FSListDir(const std::string& ph) const
{
	std::list<std::string>	ret;
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	std::string path = ph;
	path += "/*";

	 hFind = FindFirstFile(path.c_str(), &FindFileData);
	 if (hFind == INVALID_HANDLE_VALUE)
		 ;
	 else
		 ret.push_back(FindFileData.cFileName);
	 while(FindNextFile(hFind, &FindFileData) != 0)
	 {
		ret.push_back(FindFileData.cFileName);
	 }
	 FindClose(hFind);
	 return (ret);
}

