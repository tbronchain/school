#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IModule
	* \brief interface which describes a module
	*/
	class										IModule
	{
	public:
		~IModule() {};
	/**
	* \fn const std::string& getName ()
	* \brief return the name of the plugin
	* \return const std::string& return the name of the plugin
	*/
	const std::string&							getName(void);
	/**
	* \fn unsigned int getVersion ()
	* \brief return the version of the plugin
	* \return unsigned int return the version of the plugin
	*/
	unsigned int								getVersion(void);
	
	private:
	};
}
