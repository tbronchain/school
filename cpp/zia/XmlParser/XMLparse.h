#ifndef XMLPARSE_H_
# define XMLPARSE_H_

#include <stdexcept>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>

#include "IConf.hpp"

#define DEFAULT_PORT  "8080"
#define DEFAULT_THREAD_NUMBER  "1"
#define DEFAULT_ROOT_DIR  "./www"

enum
{
	ERROR_ARGS = 1,
	ERROR_XERCES_INIT,
	ERROR_PARSE,
	ERROR_EMPTY_DOCUMENT
};



class							XMLparser
{
public:
	enum StringValue
	{
		module,
		port,
		thread_number,
		index,
		root_dir,
		ssl_port,
		php_bin,
		pl_bin,
		py_bin,
		ssl_module
	};
	XMLparser();
	~XMLparser();
	bool						confExist(const std::string & file);
	void						parseConfigFile(std::string& configFile);
	bool						readConfigFile(std::string&);
	void						putDefaultValues();
	void						serverNodeLoop(std::string& configFile);
	void						getAttributes(xercesc_3_1::DOMElement *currentElement);
	zia::api::IConf&			getConf();

private:
	zia::api::IConf				conf;
	xercesc::XercesDOMParser	*ConfigFileParser_;
	std::map<std::string, StringValue> params;
};

#endif //!XMLPARSE_H_
