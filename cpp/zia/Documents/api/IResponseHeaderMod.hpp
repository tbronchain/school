#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IResponseHeaderMod
	* \brief interface which represent a module to modify the response header
	*/
	class								IResponseHeaderMod : public IModule
	{
	public:
		~IResponseHeaderMod() {};
	/**
	* \fn bool run (response& response_, const request& request_, std::map<std::string, std::string>& ressource_)
	* \brief run the module
	* \param response_ Response Object that represents the header of the response.
	* \param request_ Request Object that contain the request
	* \param ressource_ shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(response& response_, const request& request_, std::map<std::string, std::string>& ressource_) = 0;
	private:
	};
}
