#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>
#include "init.hpp"

const short	BUF_SIZE=4096;

char* ARGS[] =
  {
    "php-cgi",
    "-n",
    NULL,
    NULL
  };

class	CGI : public zia::api::IModule
{
public:
  CGI(const std::string& phpBin)
  {
    this->phpBin_ = phpBin;
    this->buf = new char[BUF_SIZE + 1];
  }
  virtual ~CGI()
  {
  }
  
  void		module_delete(zia::api::IConnection&)
  {
  }

  void		execPOST(zia::api::IMessage& msg, zia::api::AStream* input)
  {
    int		rPipes[2];
    int		wPipes[2];
    int		pid;
    int		status;
    int		n = 0;
    std::string	filename = "SCRIPT_FILENAME=";
    std::string	type = "CONTENT_TYPE=";;
    std::string	length = "CONTENT_LENGTH=";
    filename += "./www/";
    filename += ARGS[2];
    
    type += msg.http()["http"]["content-type"].mValue;
    length +=  msg.http()["http"]["content-length"].mValue;
    
    char* const myEnviron[] = {
      "REDIRECT_STATUS=200",
      const_cast<char*>(filename.c_str()),
      "REQUEST_METHOD=POST",
      const_cast<char*>(type.c_str()),
      const_cast<char*>(length.c_str()),
      NULL
    };

    if (pipe(rPipes) == -1 || pipe(wPipes) == -1)
      {
	std::cerr << "pipe: error" << std::endl;
      }

    if ((pid = fork()) == 0) // son
      {
	close(0);
	close(1);
	close(wPipes[0]);
	close(rPipes[1]);

	if (dup2(wPipes[1], 1) == -1 || dup2(rPipes[0], 0) == -1)
	  {
	    std::cerr << "dup2: error" << std::endl;
	    exit(EXIT_FAILURE);
	  }
	if (execve(this->phpBin_.c_str(), ARGS, myEnviron) == -1)
	  {
	    std::cerr << "execve: error" << std::endl;
	    exit(EXIT_FAILURE);
	  }
      }
    else if (pid > 0) // father
      {
	close(wPipes[1]);
	close(rPipes[0]);

	 memset(this->buf, 0, 4096);

	while (input->canRead())
	  {
	    input->read(this->buf, 4096);
	    if (strcmp(this->buf, "") == 0)
	      input->drop();
	    res += this->buf;
	    memset(this->buf, 0, 4096);
	  }
	  memset(this->buf, 0, 4096);
	if (write(rPipes[1], this->res.c_str(), this->res.size()) < 0)
	  {
	    std::cerr << "father pipe: error" << std::endl;
	  }

	close(rPipes[1]);

	    while ((n = read(wPipes[0], this->buf, BUF_SIZE)) > 0)
	      {
		this->buf[n] = '\0';
		res += this->buf;
		memset(this->buf, 0, 4096);
	      }
      }
    else // error
      {
	perror("fork: error");
      }
    
    this->out->drop();
    this->out->write(res.c_str());
  }

  void		execGET(zia::api::IMessage& msg)
  {
    int	rPipes[2];
    int	wPipes[2];
    int		pid;
    int		status;
    int		n = 0;
    std::string	filename = "SCRIPT_FILENAME=";
    std::string	query = "QUERY_STRING=";
    std::string	uri = "REQUEST_URI=";
    filename += "./www/";
    filename += ARGS[2];

    query += msg.http()["url"]["query"].mValue;
    uri +=  msg.http()["uri"].mValue;
    
    char* const myEnviron[] = {
      "REDIRECT_STATUS=200",
      const_cast<char*>(filename.c_str()),
      "REQUEST_METHOD=GET",
      const_cast<char*>(query.c_str()),
      const_cast<char*>(uri.c_str()),
      NULL
    };
    
    if (pipe(rPipes) == -1 || pipe(wPipes) == -1)
	std::cerr << "pipe: error" << std::endl;

    if ((pid = fork()) == 0) // son
      {
	close(0);
	close(1);
	close(wPipes[0]);
	close(rPipes[1]);

	if (dup2(wPipes[1], 1) == -1 || dup2(rPipes[0], 0) == -1)
	  {
	    std::cerr << "dup2: error" << std::endl;
	    exit(EXIT_FAILURE);
	  }
	if (execve(this->phpBin_.c_str(), ARGS, myEnviron) == -1)
	  {
	    std::cerr << "execve: error" << std::endl;
	    exit(EXIT_FAILURE);
	  }
      }
    else if (pid > 0) // father
      {
	close(wPipes[1]);
	close(rPipes[0]);
	close(rPipes[1]);

	    while ((n = read(wPipes[0], this->buf, BUF_SIZE)) > 0)
	      {
		this->buf[n] = '\0';
		res += this->buf;
		memset(this->buf, 0, 4096);
	      }
      }
    else // error
      {
	perror("fork: error");
      }
    this->out->drop();
    this->out->write(res.c_str());
  }

  zia::api::AStream*	execPHP(zia::api::IMessage& msg, zia::api::AStream* input)
  {
    // stream de sortie
    this->out = msg.newDataStream();
    ARGS[2] = const_cast<char*>(msg.http().get("url").mList.back().c_str());
    memset(this->buf, 0, BUF_SIZE + 1);
    if (access(this->phpBin_.c_str(), X_OK) == -1)
      {
	std::cerr << "access: PHP open error" << std::endl;
	return NULL;
      }
    
    if (msg.http()["method"] == "GET")
      {
	execGET(msg);
      }
    else if (msg.http()["method"] == "POST")
      {
	execPOST(msg, input);
      }
    return (this->out);
  }
private:
  zia::api::AStream*	out;
  char			*buf;
  std::string		res;
  std::string		phpBin_;
};

extern "C"
{
  zia::api::IModule	*module_new(std::list<zia::api::HttpStep::Pair>& stepCallbacks,
				    zia::api::IConnection& connection,
				    zia::api::IConf& conf)
  {
    CGI	*cgi = new CGI(conf["php-bin"]);

    stepCallbacks.push_back(
			    zia::api::HttpStep::Pair(zia::api::STEP_EXEC,
						     zia::api::HttpStep::Callback::create<CGI, &CGI::execPHP>(cgi)
						     )
			    );
    return (cgi);
  }
}

