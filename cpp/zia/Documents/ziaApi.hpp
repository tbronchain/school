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
* \fn const std::string& getBody() const
* \brief
* \return return the body of the request
*/
	const std::string&	getBody(void) const;
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

/*! \class Socket
* \brief interface that describes the socket methods
*/
class	Socket
{
public:
	virtual				~Socket() {};
	/**
* \fn void bindSocket ()
* \brief bind a socket on a port
* \return void
*/
	virtual void		bindSocket() = 0;
/**
* \fn void listenSocket ()
* \brief listen on a port for connexions
*
* \return void
*/
	virtual void		listenSocket() = 0;
/**
* \fn Socket* acceptSocket ()
* \brief accept a new client on the socket
*
* \return Socket* return a socket class for the new client
*/
	virtual Socket*		acceptSocket() = 0;
	/**
* \fn int sendSocket (void* buf, int len)
* \brief write on a socket
*
* \param buf buffer which contain the datas to send
* \param len size of the buf parameter
* \return int number of bytes sent
*/
	virtual int			sendSocket(void* buf, int len) = 0;
	/**
* \fn int recvSocket (void* buf, int len)
* \brief read on a socket
*
* \param buf buffer which contain the datas read
* \param len size of the buf parameter
* \return int number of bytes read
*/
	virtual int			recvSocket(void* buf, int len) = 0;
	/**
* \fn int getSocket ()
* \brief return the socket
* \return int return the socket
*/
	virtual int			getSocket() = 0;
	/**
* \fn int getLim ()
* \brief return the limit of FD
* \return int return the limit of FD
*/
	virtual int			getLim() = 0;
};

/*! \class Iplugin
* \brief interface which contain a set of modules
*/
class											Iplugin
{
public:
	~Iplugin() {};
	/**
*	\fn std::vector<api::Imodule *>& getModules ()
* \brief return the lists of Modules
* \return std::vector<api::Imodule *>& return the lists of modules
*/
	const std::vector<api::IModule *>&			getModules(void);
	/**
*	\fn const std::string& getName ()
* \brief return the name of the plugin
* \return const std::string& return the name of the plugin
*/
	const std::string&							getName(void);
		/**
*	\fn unsigned int getVersion ()
* \brief return the version of the plugin
* \return unsigned int return the version of the plugin
*/
	unsigned int								getVersion(void);
};

/*! \class IModule
* \brief interface which describes a module
*/
class											IModule
{
public:
	~IModule() {};

	enum executionTime
	{
		FIRST,
		LAST,
		ANYWHERE
	};
		/**
* \fn executionTime getExecutionTime ()
* \brief return the execution time
* \return executionTime return the execution time
*/
	virtual executionTime						getExecutionTime() = 0;
private:
};

/*! \class IParseMod
* \brief interface which represent a module to handle the parsing 
*/
class					IParseMod : public IModule
{
public:
	~IParseMod() {};
			/**
* \fn bool handleParse (request& request_, const std::string& raw_request)
* \brief run the module
* \param request_ Request Object that contain the request
* \param raw_request contain the raw request
* \return bool true continue the execution, false otherwise.
*/
	virtual bool		handleParse(request& request_, const std::string& raw_request, std::map<std::string, std::string>& ressource) = 0;
private:
};

/*! \class IRequestMod
* \brief interface which represent a module to act on the request
*/
class							IRequestMod : public IModule
{
public:
	~IRequestMod() {};
			/**
* \fn bool handleRequest (request &request_)
* \brief run the module
* \param request_ Request Object that contain the request.
* \param ressource shared Ressource for all the modules
* \return bool true continue the execution, false otherwise.
*/
	virtual bool				handleRequest(request &request_, std::map<std::string, std::string>& ressource) = 0;
private:
};

/*! \class IResponseHeaderMod
* \brief interface which represent a module to generate the response header
*/
class								IResponseHeaderMod : public IModule
{
public:
	~IResponseHeaderMod() {};
			/**
* \fn bool handleResponseHeader (request &request_, response &response_)
* \brief Fonction qui execute le module
* \param request_ Request Object that contain the request
* \param response Response Object that represents the header of the response.
* \param ressource shared Ressource for all the modules
* \return bool true continue the execution, false otherwise.
*/
	virtual bool					handleResponseHeader(request &request_, response &response_, std::map<std::string, std::string>& ressource) = 0;
private:
};

/*! \class IResponseHeaderBodyMod
* \brief interface which represent a module to act on the response header
*/
class								IResponseHeaderBodyMod : public IModule
{
public:
	~IResponseHeaderBodyMod() {};
			/**
* \fn bool handleResponseHeaderBody (request &request_, response *response_, std::string &to_fill)
* \brief Fonction qui execute le module
* \param request_ Request Object that contain the request
* \param response_ Response Object that represents the header of the response.
* \param to_fill string that we need to fill
* \param ressource shared Ressource for all the modules
* \return bool true continue the execution, false otherwise.
*/
	virtual bool					handleResponseHeaderBody(request &request_, response &response_, std::string &to_fill, std::map<std::string, std::string>& ressource) = 0;
};

/*! \class IExecutionMod
* \brief interface which represent a module to execute scripts
*/
class						IExecutionMod : public IModule
{
public:
	~IExecutionMod() {};
			/**
* \fn bool handleExecution (request &request_, response &response_, std::string& to_fill)
* \brief Fonction qui execute le module
* \param request_ Request Object that contain the request
* \param response_ Response Object that represents the header of the response.
* \param to_fill string that we need to fill
* \param ressource shared Ressource for all the modules
* \return bool true continue the execution, false otherwise.
*/
	virtual bool			handleExecution(request &request_, response &response_, std::string& to_fill, std::map<std::string, std::string>& ressource) = 0;
private:
};

/*! \class IEndResponseBodyMod
* \brief interface which represent a module to add some datas at the end of the response content
*/
class								IEndResponseBodyMod : public IModule
{
public:
	~IEndResponseBodyMod() {};
/**
* \fn bool handleEndResponseBody (request &request_, response *response_, std::string &to_fill)
* \brief Fonction qui permet d'exectuer le module
*
* \param request_ Request Object that contain the request
* \param response_ Response Object that represents the header of the response.
* \param to_fill string that we need to fill
* \param ressource shared Ressource for all the modules
* \return bool true continue the execution, false otherwise.
*/
	virtual bool					handleEndResponseBody(request &request_, response &response_, std::string &to_fill, std::map<std::string, std::string>& ressource) = 0;
};

}
