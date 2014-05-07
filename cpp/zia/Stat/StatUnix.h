#ifndef STATUNIX_H
# define STATUNIX_H

#include <sys/stat.h>

#include "IStat.h"

class statUnix: public IStat
{
public:
	int			fullStruct(std::string filename);
	int			getSize();
	std::string	getSizeString();
	std::string	lastModified();
	bool		isDir();
protected:
private:
	struct stat	_buf;
};


#endif //!STATUNIX_H
