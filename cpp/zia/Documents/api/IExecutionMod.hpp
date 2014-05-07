#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IExecutionMod
	* \brief interface which represent a module to execute scripts
	*/
	class						IExecutionMod : public IModule
	{
	public:
		~IExecutionMod() {};
	/**
	* \fn bool run (std::string& toFill, int& fd, const request& request_, const response& response_, std::map<std::string, std::string>& ressource_)
	* \brief Fonction qui execute le module
	* \param toFill String to fill with the content to add (leave empty if not used)
	* \param fd File descriptor to use instead of the string (leave 0 if not used)
	* \param request_ Request Object that contain the request
	* \param response_ Response Object that represents the header of the response.
	* \param ressource_ shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise
	*/
		virtual bool			run(std::string& toFill, int& fd, const request& request_, const response& response_, std::map<std::string, std::string>& ressource_) = 0;
	private:
	};
}
