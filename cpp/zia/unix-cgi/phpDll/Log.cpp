#include <stdio.h>
#include "Log.h"

Log::Log()
{
	std::string	file = "Log.txt";
#ifdef _WIN32
	this->iFile_.open(file.c_str(), std::ios::app);
	if (this->iFile_.bad())
		std::cerr << "cannot open Log.txt file" << std::endl;
#else
	std::string name = "./Visual/zia/";
	name += file;
	this->iFile_.open(name.c_str(), std::ios::app);
#endif
}

Log::~Log()
{
	this->iFile_.close();
}

Log&	Log::operator << (zia::api::LogLevel level)
{
	switch (level)
	{
	case 4 :
		this->mLine << "Information :";
	break;
	}
	return (*this);
}

void	Log::flush()
{
	std::string str = this->mLine.str();
	this->iFile_ << str << std::endl;
	this->iFile_.flush();
	this->mLine.clear();
}

void	Log::print(zia::api::LogLevel level, const char *format, ...)
{

}
