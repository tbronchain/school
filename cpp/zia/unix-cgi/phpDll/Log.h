#ifndef LOG_H_
# define LOG_H_

#include <fstream>

#include "ILog.hpp"

class	Log : public zia::api::ILog
{
public:
	Log();
	virtual ~Log();
	Log&	operator << (zia::api::LogLevel level);
	void	flush();
	void	print(zia::api::LogLevel level, const char * format, ...);

	std::ofstream	iFile_;
};

#endif //!LOG_H_