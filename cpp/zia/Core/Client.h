#ifndef CLIENT_H_
# define CLIENT_H_

# include <iostream>
# include <fstream>
# include <sstream>
# include <deque>
# include <string>
# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <ctime>
//# include <io.h>

# include "mtime.h"
# include "mio.h"
# include "Socket.h"
# include "MemoryDefines.h"
# include "Module.h"
# include "Log.h"
# include "HttpStep.hpp"
# include "HttpMessage.h"
# include "CircularBuffer.hpp"
# include "IStat.h"

const static unsigned int TIME_END	= 150000;
const static unsigned int BUF_SIZE	= 4096;
const static char * const EOL			= "\r\n\r\n";
const static  unsigned int EOL_SIZE	= 4;

class Server;

class Client
{
public:
    Client();
    CircularBuffer<char>		&getReadCircularBuffer();
    std::string getBody();
    void                                initClient(Socket* s, Server *serv);
    void                                resetClient();
    ~Client();

    Socket*				getSocket() const;
    //DescriptorReader&	getDescriptorReader();

    // read/write functions
    int					readData();
    int					writeData();

    bool				isRData();
    bool				isWData();

    std::string                 	getHeader();
    Server*				getServer();
    
    std::string                 	getData();
    void				setData(const std::string&);
    void				setData(unsigned int);
    void				delData();

    // time functions
    const timeval&              	getBegin() const;
    const timeval&              	getEnd();
    void                    		setEnd(unsigned int pause);
    void				resetEnd();
    bool				isEnd();
    int					getTimeout(int old);
    
    // persistent functions
    bool				isPersistent() const;
    void				isPersistent(bool);
    
    // API handle
    zia::api::AStream*          	getInput() const;
    zia::api::AStream*                  getOutput() const;
    zia::api::IMessage*                 getMessage() const;
    bool				checkIfModAtStep(zia::api::HttpStepID sId);
    zia::api::AStream*          	execMethodAtStep(zia::api::HttpStepID sId, zia::api::AStream* input);
    IStat*				getStat() const;
    
private:
    Socket*				socket_;

    // read/write buffers
    char				rbuf_[BUF_SIZE + 1];
    char				wbuf_[BUF_SIZE + 1];

    // read/write queues
    CircularBuffer<char>		readCircularBuffer;

    std::deque< std::pair<unsigned int, std::string> >		wstrings_;

    // API handle
    zia::api::IMessage*				message_;
    zia::api::AStream*				input_;
    zia::api::AStream*				output_;
    std::list< zia::api::HttpStep::Pair >	modsCallback_;

    timeval                                     begin_;
    timeval                                     tvend_;
    unsigned int                                end_;
    bool                                	isPersistent_;
    Server*                             	_serv;
    IStat*                              	stat_;

public:
    bool                                	isBody_;
};

#endif // CLIENT_H_
