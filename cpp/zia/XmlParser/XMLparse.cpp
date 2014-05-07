#include "DataTree.hpp"
#include "XMLparse.h"

using namespace xercesc;

XMLparser::XMLparser()
{
	try
	{
		// initialize the lib
		XMLPlatformUtils::Initialize();
	}
	catch(XMLException& e)
	{
		char* message = XMLString::transcode(e.getMessage());
		std::cerr << "XML toolkit initialization error: " << message << std::endl;
		XMLString::release(&message);
	}
	this->ConfigFileParser_ = new XercesDOMParser;
	this->params["module"] = this->module;
	this->params["port"] = this->port;
	this->params["index"] = this->index;
	this->params["thread-number"] = this->thread_number;
	this->params["root-dir"] = this->root_dir;
	this->params["php-bin"] = this->php_bin;
	this->params["pl-bin"] = this->pl_bin;
	this->params["py-bin"] = this->py_bin;
	this->params["ssl-module"] = this->ssl_module;
	this->params["ssl-port"] = this->ssl_port;
}

XMLparser::~XMLparser()
{
	try
	{
		XMLPlatformUtils::Terminate();
	}
	catch(xercesc::XMLException& e)
	{
		char* message = xercesc::XMLString::transcode( e.getMessage() );
		std::cerr << "XML toolkit teardown error: " << message << std::endl;
		XMLString::release(&message);
	}
}

bool	XMLparser::confExist(const std::string & file) 
{ 
	FILE  *fp;
	fp = fopen(file.c_str(), "rb");

  if (fp == NULL)
      return (false);
  else
    {
      fclose(fp);
      return (true);
    }
} 

void			XMLparser::parseConfigFile(std::string& configFile)
{
	DOMElement	*currentElement;
	DOMElement	*elementRoot;
	DOMNode		*currentNode;
	DOMNodeList	*children;
	XMLSize_t	nodeCount;
	DOMDocument	*xmlDoc;

	this->ConfigFileParser_->parse(configFile.c_str());
	xmlDoc = this->ConfigFileParser_->getDocument();
	elementRoot = xmlDoc->getDocumentElement();

	if (!elementRoot)
		std::cerr << "empty XML document" << std::endl;

	children = elementRoot->getChildNodes();
	nodeCount = children->getLength();
	for(XMLSize_t xx = 0; xx < nodeCount; ++xx)
	{
		currentNode = children->item(xx);
		if(currentNode->getNodeType() &&
			currentNode->getNodeType() == DOMNode::ELEMENT_NODE)
		{
			currentElement = dynamic_cast< xercesc::DOMElement* >(currentNode);
			this->getAttributes(currentElement);
		}
	}
	if (conf["port"].mValue.empty() || conf["thread-number"].mValue.empty() || conf["root-dir"].mValue.empty())
	  {
		this->putDefaultValues();
	  }	
}

zia::api::IConf&	XMLparser::getConf()
{
	return (this->conf);
}

void				XMLparser::getAttributes(DOMElement	*currentElement)
{
	std::string		name = XMLString::transcode(currentElement->getTagName());
	const XMLCh		*xmlch_elem;

	switch (this->params[name])
	{
		case XMLparser::port :
			xmlch_elem = currentElement->getTextContent();
			conf["port"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::module :
			xmlch_elem = currentElement->getTextContent();
			conf["modules"].mList.push_back(XMLString::transcode(xmlch_elem));
		break;

		case XMLparser::index :
			xmlch_elem = currentElement->getTextContent();
			conf["index"].mList.push_back(XMLString::transcode(xmlch_elem));
		break;

		case XMLparser::thread_number :
			xmlch_elem = currentElement->getTextContent();
			conf["thread-number"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::root_dir :
			xmlch_elem = currentElement->getTextContent();
			conf["root-dir"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::php_bin :
			xmlch_elem = currentElement->getTextContent();
			conf["php-bin"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::pl_bin :
			xmlch_elem = currentElement->getTextContent();
			conf["pl-bin"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::py_bin :
			xmlch_elem = currentElement->getTextContent();
			conf["py-bin"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::ssl_module :
			xmlch_elem = currentElement->getTextContent();
			conf["ssl-module"] = XMLString::transcode(xmlch_elem);
		break;

		case XMLparser::ssl_port :
			xmlch_elem = currentElement->getTextContent();
			conf["ssl-port"] = XMLString::transcode(xmlch_elem);
		break;
	}

}

bool	XMLparser::readConfigFile(std::string& configFile)
{
	if (!this->confExist(configFile))
	  return (false);
	this->ConfigFileParser_->setValidationScheme(XercesDOMParser::Val_Never);
	this->ConfigFileParser_->setDoNamespaces(false);
	this->ConfigFileParser_->setDoSchema(false);
	this->ConfigFileParser_->setLoadExternalDTD(false);

	try
	{
		parseConfigFile(configFile);
	}
	catch(xercesc::XMLException& e)
	{

		char* message = xercesc::XMLString::transcode(e.getMessage());
		std::ostringstream errBuf;
		std::cerr << "Error parsing file: " << message << std::flush;
		XMLString::release(&message);
		return (false);
	}
	return (true);
}

void		XMLparser::putDefaultValues()
{
	conf["port"] = DEFAULT_PORT;
	conf["thread-number"] = DEFAULT_THREAD_NUMBER;
	conf["root-dir"] = DEFAULT_ROOT_DIR;
	//conf["php-bin"] = XMLString::transcode(xmlch_elem);
}
