//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Server.h"
#include "httpExec.h"

httpExec::httpExec()
{
#ifdef _WIN32
	this->fs_ = new WindowsFileSystem();
#else
	this->fs_ = new UnixFileSystem();
#endif
	this->map_["GET"]	= &httpExec::eGet;
	this->map_["PUT"]	= &httpExec::ePut;
	this->map_["POST"]	= &httpExec::ePost;
	this->map_["HEAD"]	= &httpExec::eHead;
	this->map_["OPTIONS"]	= &httpExec::eOptions;
	this->map_["DELETE"]	= &httpExec::eDelete;
	this->map_["TRACE"]	= &httpExec::eTrace;
	this->map_["CONNECT"]	= &httpExec::eConnect;
	this->mapext_["txt"]	= "text/plain";
	this->mapext_["html"]	= "text/html";
	this->mapext_["css"]	= "text/css";
	this->mapext_["xml"]	= "text/xml";
	this->mapext_["csv"]	= "text/csv";
	this->mapext_["js"]		= "text/javascript";
	this->mapext_["mov"]	= "video/quicktime";
	this->mapext_["ogg"]	= "video/ogg";
	this->mapext_["mp4"]	= "video/mp4";
	this->mapext_["mpeg"]	= "video/mpeg";
	this->mapext_["mp3"]	= "audio/mpeg";
	this->mapext_["jpeg"]	= "image/jpeg";
	this->mapext_["jpg"]	= "image/jpeg";
	this->mapext_["gif"]	= "image/gif";
	this->mapext_["png"]	= "image/png";
}

httpExec::~httpExec()
{
}

std::map<std::string, httpExec::EXECPTR>&		httpExec::getMap()
{
	return this->map_;
}

bool		httpExec::isReadable(const std::string& file) const
{
    std::ifstream f(file.c_str());
    return !f.fail(); 
}

void		httpExec::setHeader(Client& c, const char* code, const char* reason, bool error)
{
	//c.getMessage()->httpResp() = c.getMessage()->http();
	c.getMessage()->httpResp()["version"] = c.getMessage()->http()["version"].mValue;
	c.getMessage()->httpResp()["code"] = code;
	c.getMessage()->httpResp()["reason"] = reason;
	c.getMessage()->httpResp()["http"]["Server"] = "ZIA 1.0";
	c.getMessage()->httpResp()["http"]["Accept-Ranges"] = "bytes";
	c.getMessage()->httpResp()["http"]["Vary"] = "Accept-Encoding";
	if (error == false)
	{
		c.getMessage()->httpResp()["http"]["Connection"] = "keep-alive";
		c.getMessage()->httpResp()["http"]["Keep-Alive"] = "timeout=15, max=100";
	}
	else
	{
		c.getMessage()->httpResp()["http"]["Connection"] = "close";
		c.isPersistent(false);
	}
	/*unsigned int	i;
	if (c.getMessage()->http().get("url").mList.empty() == false)
	{
	  if (c.getMessage()->http().get("url").mList.back().empty() == false)
	    {
	      if ((i = c.getMessage()->http().get("url").mList.back().find_last_of('.')) != std::string::npos)
		{
		  std::string	extension;
		  
		  extension = c.getMessage()->http().get("url").mList.back().substr(i + 1, std::string::npos);
		  c.getMessage()->httpResp()["http"]["Content-Type"] = this->mapext_[extension];
		  if (c.getMessage()->httpResp()["http"]["Content-Type"] == "")
		    c.getMessage()->httpResp()["http"]["Content-Type"] = "text/html";
		}
	    }
	}
	else*/
		c.getMessage()->httpResp()["http"]["Content-Type"] = "text/html";
	/*if (c.getStat()->getSize() > 0)
	{
		c.getMessage()->httpResp()["http"]["Content-Length"] = c.getStat()->getSizeString();
		c.getMessage()->httpResp()["http"]["Connection"] = "close";
	}*/
	if (c.getStat()->lastModified() != "")
		c.getMessage()->httpResp()["http"]["Last-Modified"] = c.getStat()->lastModified();
	c.setData(static_cast<HttpMessage *>(c.getMessage())->httpRespString());
}

void		httpExec::checkUrl(Client& c, std::string& file, bool& run, bool& isDir, bool& isFile, std::list<std::string>& dir_content)
{
	if (c.getMessage()->http().has("url") == true)
	{
		for (std::list<std::string>::const_iterator it = c.getMessage()->http().get("url").mList.begin();
			it != c.getMessage()->http().get("url").mList.end();
			++it)
		{
			file += "/";
			file += (*it);
		}
	}

	if (c.getStat() == NULL)
	{
		c.setData(0);
		return ;
	}
	else
	{
		if (c.getStat()->fullStruct(file) == 0)
			run = true;
		else
		{
			if (this->isReadable(file) == true)
			{
				isFile = true;
			}
		}
	}

	if (run && c.getStat()->isDir() == false)
	{
		isFile = true;
	}
	else if (run && c.getStat()->isDir() == true)
	{
		std::string tmp_file;

		if (c.getServer()->getConf()["index"].mList.empty() == false)
		{
			for (std::list<std::string>::const_iterator it = c.getServer()->getConf()["index"].mList.begin();
				it != c.getServer()->getConf()["index"].mList.end();
				++it)
			{
				tmp_file = file;
				tmp_file += "/";
				tmp_file += *it;
				if (c.getStat())
				{
					if (c.getStat()->fullStruct(tmp_file) == 0)
					{
						file = tmp_file;
						isDir = false;
						isFile = true;
						break ;
					}
				}
			}
		}

		if (isFile == false)
		{
			isDir = true;
			dir_content = this->fs_->FSListDir(file);
		}
	}
}

void		httpExec::eGet(Client& c)
{
	std::list<std::string>	dir_content;
	Server *s = c.getServer();
	std::string file = s->getConf()["root-dir"];

	bool run = false;
	bool isFile = false;
	bool isDir = false;

	this->checkUrl(c, file, run, isDir, isFile, dir_content);

	// si le nom du fichier comporte une extension php
	if (isFile && (checkExtension(file, ".php") == true))
	  {
	    execPhpMod(c);
	  }
	else if (isFile)
	{
		int f = open(file.c_str(), O_RDONLY);
		if (f > 0)
		{
			this->setHeader(c, "200", "OK", false);
			c.setData(EOL);
			c.setData(f);
			c.setData(EOL);
		}
		else
		{
			this->setHeader(c, "404", "NOT FOUND", true);
			c.setData(EOL);
			c.setData("404: NOT FOUND");
			c.setData(EOL);
		}
	}
	else if (isDir)
	{
		this->setHeader(c, "200", "OK", false);
		c.setData(EOL);

		std::string folder = "";

		if (c.getMessage()->http().has("url") == true)
		{
			for (std::list<std::string>::const_iterator it = c.getMessage()->http().get("url").mList.begin();
				it != c.getMessage()->http().get("url").mList.end();
				++it)
			{
				folder += "/";
				folder += (*it);
			}
		}

		std::string d = "<html><head></head><body>";
		for (std::list<std::string>::iterator listIt = dir_content.begin();
			listIt != dir_content.end();
			++listIt)
		{
			d += "<a href=\"";
			if (folder.empty() == false)
			{
				d += folder;
				d += "/";
			}
			d += *listIt;
			d += "\">";
			d += *listIt;
			d += "</a>";
			d += "<br />";
		}
		d += "</body></html>";
		c.setData(d);
		c.setData(EOL);
	}
	else
	{
		this->setHeader(c, "404", "NOT FOUND", true);
		c.setData(EOL);
		c.setData("404: NOT FOUND");
		c.setData(EOL);
	}
}

void		httpExec::eHead(Client& c)
{
	Server *s = c.getServer();
	std::string file = s->getConf()["root-dir"];
	std::list<std::string>	dir_content;

	bool run = false;
	bool isFile = false;
	bool isDir = false;

	this->checkUrl(c, file, run, isDir, isFile, dir_content);

	// si le nom du fichier comporte une extension php
	if (isFile || isDir)
	{
		this->setHeader(c, "200", "OK", false);
		c.setData(EOL);
		c.setData("200: OK");
		c.setData(EOL);
	}
	else
	{
		this->setHeader(c, "404", "NOT FOUND", true);
		c.setData(EOL);
		c.setData("404: NOT FOUND");
		c.setData(EOL);
	}
}

void		httpExec::ePut(Client& c)
{
	std::string		file = "./www";

	c.getMessage()->httpResp() = c.getMessage()->http();
	if (c.getMessage()->http().has("url") == true)
	{
		std::list<std::string>::const_iterator	it = c.getMessage()->http().get("url").mList.begin();
		std::list<std::string>::const_iterator	itEnd = c.getMessage()->http().get("url").mList.end();

		for (;it != itEnd; ++it)
		{
			file += "/";
			file += (*it);
		}
	}


	int f = open(file.c_str() , O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);
	if (f > 0)
	{
		c.setData(f);
		c.isBody_ = true;
	}
	else
		c.setData(EOL);
/*	c.getMessage()->httpResp()["code"] = "501";
	c.getMessage()->httpResp()["reason"] = "NOT IMPLEMENTED";
	c.setData("501: NOT IMPLEMENTED");*/
}

void		httpExec::ePost(Client& c)
{
	c.getMessage()->httpResp() = c.getMessage()->http();
	c.isBody_ = true;
}

void		httpExec::eDelete(Client& c)
{
	c.getMessage()->httpResp() = c.getMessage()->http();
	c.getMessage()->httpResp()["code"] = "501";
	c.getMessage()->httpResp()["reason"] = "NOT IMPLEMENTED";
	this->setHeader(c, "501", "NOT IMPLEMENTED", true);
	c.setData(EOL);
	c.setData("501: NOT IMPLEMENTED");
	c.setData(EOL);
}

void		httpExec::eOptions(Client& c)
{
	c.getMessage()->httpResp() = c.getMessage()->http();
	c.getMessage()->httpResp()["code"] = "501";
	c.getMessage()->httpResp()["reason"] = "NOT IMPLEMENTED";
	this->setHeader(c, "501", "NOT IMPLEMENTED", true);
	c.setData(EOL);
	c.setData("501: NOT IMPLEMENTED");
	c.setData(EOL);
}

void		httpExec::eTrace(Client& c)
{
	c.getMessage()->httpResp() = c.getMessage()->http();
	c.getMessage()->httpResp()["code"] = "501";
	c.getMessage()->httpResp()["reason"] = "NOT IMPLEMENTED";
	this->setHeader(c, "501", "NOT IMPLEMENTED", true);
	c.setData(EOL);
	c.setData("501: NOT IMPLEMENTED");
	c.setData(EOL);
}

void		httpExec::eConnect(Client& c)
{
	c.getMessage()->httpResp() = c.getMessage()->http();
	c.getMessage()->httpResp()["code"] = "501";
	c.getMessage()->httpResp()["reason"] = "NOT IMPLEMENTED";
	this->setHeader(c, "501", "NOT IMPLEMENTED", true);
	c.setData(EOL);
	c.setData("501: NOT IMPLEMENTED");
	c.setData(EOL);
}

bool		httpExec::checkExtension(const std::string& item, const char* ext)
{
		if (item.find(ext) != std::string::npos)
		      return (true);
		return (false);
}

void					httpExec::execPhpMod(Client &c)
{
	zia::api::AStream	*output = c.getOutput();
	char*				buff = new char[4096];
	std::string			res;
	
	memset(buff, 0, 4096);

	if (c.checkIfModAtStep(zia::api::STEP_EXEC) == true)
		{
			output = c.execMethodAtStep(zia::api::STEP_EXEC, c.getInput());
			while (output->canRead())
			{
			  output->read(buff, 4096);
			  if (strcmp(buff, "") == 0)
			    output->drop();
			  res += buff;
			  memset(buff, 0, 4096);
			}
			std::string new_res = "HTTP/1.1 200 OK\r\n";
			new_res += res;
			c.setData(new_res);
			c.setData(EOL);
			output->drop();
		}
}
