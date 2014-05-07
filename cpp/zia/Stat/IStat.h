#ifndef ISTAT_H
# define ISTAT_H

#include <iostream>

class IStat
{
public:
	virtual int			fullStruct(std::string filename) = 0;
	virtual int			getSize() = 0;
	virtual std::string	getSizeString() = 0;
	virtual std::string	lastModified() = 0;
	virtual	bool		isDir() = 0;
protected:
private:
};

# ifdef _WIN32
class statWindows;
typedef statWindows ABSSTAT;
#  include "StatWindows.h"
# else
class statUnix;
#  include "StatUnix.h"
typedef statUnix ABSSTAT;
# endif

#endif //!ISTAT_H