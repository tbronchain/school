#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IDataModOut
	* \brief interface which represent a module to modify the output body
	*/
	class								IDataModOut : public IModule
	{
	public:
		~IDataModOut() {};
	/**
	* \fn bool run (char* dest, const char* src, int src_len, std::map<std::string, std::string>& ressource_)
	* \brief Fonction qui execute le module
	* \param dest Pointer on the new allocated buffer
	* \param src Pointer on the old allocated buffer
	* \param src_len Lenght of the old buffer
	* \param ressource_ shared Ressource for all the modules
	* \return int Size of the dest buffer, 0 to use the src buffer, < 0 for a fatal error
	*/
		virtual int					run(char* dest, const char* src, int src_len, std::map<std::string, std::string>& ressource_) = 0;
	private:
	};
}
