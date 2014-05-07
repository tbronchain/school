#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class response
	* \brief classe qui permet de stocker le header de la reponse
	*/
	class response
	{
	public:
		response();
		~response();
	/**
	* \fn void setField (const std::string& key, const std::string& value)
	* \brief
	* \param key, key of the header field
	* \param value, value of the header field 
	* \return void
	*/
		void	setField(const std::string& key, const std::string& value);
	/**
	* \fn void	setVersion (const std::string& version)
	* \brief
	* \param version, version of the response 
	* \return void
	*/
		void	setVersion(const std::string& version);
	/**
	* \fn void	setCode (const std::string& code)
	* \brief
	* \param code, code of the request state 
	* \return void
	*/
		void	setCode(const std::string& code);
	/**
	* \fn void	getFields ()
	* \brief 
	* \return std::map<std::string, std::string>& which contains all the fields
	*/
		std::map<std::string, std::string>&		getFields();
	/**
	* \fn std::string&	getVersion ()
	* \brief
	* \return std::string& return the version of the response
	*/
		std::string&							getVersion();
	/**
	* \fn std::string& getCode();
	* \brief
	* \return std::string& return the code of the request state
	*/
		std::string&							getCode();

	private:
		std::map<std::string, std::string>		_fields;
		std::string								_version;
		std::string								_code;
	};
}
