#ifndef STATWINDOWS_H
# define STATWINDOWS_H

#include "IStat.h"

class statWindows: public IStat
{
public:
	int			fullStruct(std::string filename);
	int			getSize();
	std::string	getSizeString();
	std::string	lastModified();
	bool		isDir();
protected:
private:
	struct _stat _buf;
};


#endif //!STATWINDOWS_H