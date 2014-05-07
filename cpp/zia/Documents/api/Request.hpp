#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class request
	* \brief classe qui permet de stocker une requete
	*/
	class	request
	{
	public:

		request();
		~request();
	/**
	* \fn const std::string& getRequest() const
	* \brief
	* \return return the entire request
	*/
		const std::string&	getRequest(void) const;
	/**
	* \fn const std::string& getMethod() const
	* \brief
	* \return return the method of the request
	*/
		const std::string&	getMethod(void) const;
	/**
	* \fn const std::string& getUri() const
	* \brief
	* \return return the URI of the request
	*/
		const std::string&	getUri(void) const;
	/**
	* \fn const std::string& getVersion() const
	* \brief
	* \return return the version of the request
	*/
		const std::string&	getVersion(void) const;
	/**
	* \fn const std::string& getField() const
	* \brief
	* \return return one header field
	*/
		const std::string&	getField(const std::string& key) const;
	/**
	* \fn const std::map<std::string, std::string>& getFields() const
	* \brief
	* \return return all the header's field
	*/
		const std::map<std::string, std::string>&	getFields(void) const;

	/**
	* \fn void	setRequest (const std::string& request)
	* \brief
	* \param request, string who contain the request 
	* \return void
	*/
		void									setRequest(const std::string& request);
	/**
	* \fn void	setField(const std::string& key, const std::string& value)
	* \brief
	* \param key, key of the header field
	* \param value, value of the header field
	* \return void
	*/
		void									setField(const std::string& key, const std::string& value);
	/**
	* \fn void	setMethod(const std::string& method)
	* \brief
	* \param method, method of the request 
	* \return void
	*/
		void									setMethod(const std::string& method);
	/**
	* \fn void	setUri(const std::string& uri)
	* \brief
	* \param uri, uri of the request
	* \return void
	*/
		void									setUri(const std::string& uri);
	/**
	* \fn void	setVersion (const std::string& version)
	* \brief
	* \param version, version of the request
	* \return void
	*/
		void									setVersion(const std::string& version);
	/**
	* \fn bool	isBody() const
	* \brief inform if there is a body
	* \param 
	* \return bool
	*/
		bool									isBody() const;

	private:
		std::string								_request;
		std::map<std::string, std::string>		_fields;
		std::string								_method;
		std::string								_uri;
		std::string								_version;
		bool									_body;
	};
}
