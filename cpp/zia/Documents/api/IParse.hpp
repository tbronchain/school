#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IParse
	* \brief interface which represent a module to handle the parsing 
	*/
	class					IParse : public IModule
	{
	public:
		~IParse() {};
	/**
	* \fn bool run (request& request_, const std::string& raw_request, std::map<std::string, std::string>& ressource_)
	* \brief run the module
	* \param request_ Request Object that contain the request
	* \param rawRequest contain the raw request
	* \param ressource_ shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool		run(request& request_, const std::string& rawRequest, std::map<std::string, std::string>& ressource_) = 0;
	private:
	};
}
