#include <stdio.h>
#include "Log.h"

/*
Core/Log.cpp:18: attention : enumeration value ‘LOG_ASSERT’ not handled in switch
Core/Log.cpp:18: attention : enumeration value ‘LOG_WARN’ not handled in switch
Core/Log.cpp:18: attention : enumeration value ‘LOG_DEBUG’ not handled in switch
Core/Log.cpp:18: attention : enumeration value ‘LOG_DEBUG2’ not handled in switch
OB*/
  
Log::Log()
{
	this->iFile_.open("Log.txt", std::ios::app);
	if (this->iFile_.bad())
		std::cerr << "cannot open Log.txt file" << std::endl;
}

Log::~Log()
{
	this->iFile_.close();
}

Log&	Log::operator << (zia::api::LogLevel level)
{
  switch (level)
    {

    case zia::api::LOG_ERR :
      this->mLine << "Error :";
      break;

    case  zia::api::LOG_ASSERT :
      this->mLine << "Assertion :";
    break;
    case  zia::api::LOG_WARN :
      this->mLine << "Warning :";
    break;
    case  zia::api::LOG_DEBUG :
      this->mLine << "Debug :";
    break;
    case  zia::api::LOG_DEBUG2 :
      this->mLine << "Debug 2 :";
    break;
    case zia::api::LOG_INFO :
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

void	Log::print(zia::api::LogLevel, const char *, ...)
{

}
