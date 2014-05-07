#include "StatUnix.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <sstream>

int		statUnix::fullStruct(std::string filename)
{
	int result;

	// Get data associated with "crt_stat.c": 
	result = stat(filename.c_str(), &this->_buf);

	// Check if statistics are valid: 
	if (result != 0)
	  {
		//throw
	  }

	return result;
}

int			statUnix::getSize()
{
	return this->_buf.st_size;
}

std::string	statUnix::getSizeString()
{
	std::ostringstream oss;

	oss << this->_buf.st_size;
	std::string result = oss.str();
	return (result);
}

std::string	statUnix::lastModified()
{
	struct tm	*timeinfo;
	char		timebuf[80];

	timeinfo = localtime ( &this->_buf.st_mtime );
	if (timeinfo != NULL)
		strftime (timebuf, 80, "%a, %d %b %Y %X GMT", timeinfo);
	else
		return "";
	return (timebuf);
}

bool		statUnix::isDir()
{
	return S_ISDIR(this->_buf.st_mode);
}
