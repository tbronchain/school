#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IRequestMod
	* \brief interface which represent a module to act on the request
	*/
	class							IRequestMod : public IModule
	{
	public:
		~IRequestMod() {};
	/**
	* \fn bool run (request& request_, std::map<std::string, std::string>& ressource_)
	* \brief run the module
	* \param request_ Request Object that contain the request.
	* \param ressource_ shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool				run(request& request_, std::map<std::string, std::string>& ressource_) = 0;
	private:
	};
}
