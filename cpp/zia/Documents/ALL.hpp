#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IParseMod
	* \brief interface which represent a module to handle the parsing 
	*/
	class					IParseMod : public IModule
	{
	public:
		~IParseMod() {};
	/**
	* \fn bool run (request& request_, const std::string& raw_request)
	* \brief run the module
	* \param request_ Request Object that contain the request
	* \param raw_request contain the raw request
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool		run(request& request_, const std::string& raw_request, std::map<std::string, std::string>& ressource) = 0;
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
	* \fn bool run (request &request_)
	* \brief run the module
	* \param request_ Request Object that contain the request.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool				run(request& request_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};

	/*! \class IResponseHeader
	* \brief interface which represent a module to generate the response header
	*/
	class								IResponseHeader : public IModule
	{
	public:
		~IResponseHeader() {};
	/**
	* \fn bool run (request& request_, response& response_)
	* \brief run the module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class IResponseHeaderMod
	* \brief interface which represent a module to modify the response header
	*/
	class								IResponseHeaderMod : public IModule
	{
	public:
		~IResponseHeaderMod() {};
	/**
	* \fn bool run (request &request_, response &response_)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class AddDataBegin
	* \brief interface which represent a module to add data at the beginning of the response body
	*/
	class								IAddDataBegin : public IModule
	{
	public:
		~IAddDataBegin() {};
	/**
	* \fn bool run (request &request_, response &response_)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class IExecutionMod
	* \brief interface which represent a module to execute scripts
	*/
	class						IExecutionMod : public IModule
	{
	public:
		~IExecutionMod() {};
	/**
	* \fn bool run (request &request_, response &response_, std::string& to_fill)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response_ Response Object that represents the header of the response.
	* \param to_fill string that we need to fill
	* \param ressource shared Ressource for all the modules
	* \return int > 0 : handle to use, == 0 : don't care about the result, < 0 : stop execution
	*/
		virtual bool			run(request& request_, response& response_, std::string& to_fill, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class AddDataEnd
	* \brief interface which represent a module to add data at the end of the response body
	*/
	class								IAddDataEnd : public IModule
	{
	public:
		~IAddDataEnd() {};
	/**
	* \fn bool run (request &request_, response &response_)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class DataModIn
	* \brief interface which represent a module to modify the input body
	*/
	class								IDataModIn : public IModule
	{
	public:
		~IDataModIn() {};
	/**
	* \fn bool run (request &request_, response &response_)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
	
	/*! \class DataModOut
	* \brief interface which represent a module to modify the output body
	*/
	class								IDataModOut : public IModule
	{
	public:
		~IDataModOut() {};
	/**
	* \fn bool run (request &request_, response &response_)
	* \brief Fonction qui execute le module
	* \param request_ Request Object that contain the request
	* \param response Response Object that represents the header of the response.
	* \param ressource shared Ressource for all the modules
	* \return bool true continue the execution, false otherwise.
	*/
		virtual bool					run(request& request_, response& response_, std::map<std::string, std::string>& ressource) = 0;
	private:
	};
}
