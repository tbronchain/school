#ifndef ERROR_H_
# define ERROR_H_

#include <string>
#include <exception>

class				Error : public std::exception
{
public:
	Error(const std::string &error)
	{
		_error = error;
	}
	~Error() throw ()
	{
	}
	virtual const char * what(void) const throw ()
	{
		return (_error.c_str());
	}
private:
	std::string		_error;
};

#endif //! ERROR_H_
