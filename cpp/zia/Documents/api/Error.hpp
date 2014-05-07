#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class Error
	* \brief class to handle exception of socket and modules
	*/
	class				Error : public std::exception
	{
	public:
		Error(const std::string &error)
		{
			_error = error;
		}
		virtual const char * what(void) const throw ()
		{
			return (_error.c_str());
		}

	private:
		std::string		_error;
	};
}
