#include "StatWindows.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <sstream>

int		statWindows::fullStruct(std::string filename)
{
	int result;

	// Get data associated with "crt_stat.c": 
	result = _stat(filename.c_str(), &this->_buf);

	// Check if statistics are valid: 
	if(result != 0)
		; //throw

	return (result);
}

int			statWindows::getSize()
{
	return this->_buf.st_size;
}

std::string	statWindows::getSizeString()
{
	std::ostringstream oss;

	oss << this->_buf.st_size;
	std::string result = oss.str();
	return result;
}

std::string	statWindows::lastModified()
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

bool		statWindows::isDir()
{
	if ((this->_buf.st_mode & _S_IFDIR) == _S_IFDIR)
		return true;
	return false;
}