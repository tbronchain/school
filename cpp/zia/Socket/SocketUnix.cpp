//

#include <iostream>

#include <sys/resource.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "SocketUnix.h"


SocketUnix::SocketUnix(int port, int limFd, sockaddr_in* sin, int sock)
{
    this->port_ = port;
    this->limFd_ = limFd;

    if (sock && sin)
    {
        this->sin_ = sin;
        this->sock_ = sock;
    }
    else if (!sock && !sin)
    {
        this->createSocket();
    }
    else
    {
        std::cerr << "Socket creation error" << std::endl;
    }
}

SocketUnix::~SocketUnix()
{
	if (shutdown(this->sock_, SHUT_RDWR) == -1)
		std::cerr << "shutdown error" << std::endl;
	if (::close(this->sock_) == -1)
		std::cerr << "close error" << std::endl;
    delete this->sin_;
}

void	SocketUnix::createSocket()
{
    this->sin_ = new sockaddr_in;
    memset(this->sin_, 0, sizeof(*(this->sin_)));

    this->sin_->sin_addr.s_addr	= INADDR_ANY;
    this->sin_->sin_family		= AF_INET;
    this->sin_->sin_port		= htons(this->port_);

    if ((this->sock_ = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        std::cerr << "Failed." << std::endl;
    else
        std::cerr << "Ok." << std::endl;
}

bool	SocketUnix::bindSocket() 
{
    if (bind(this->sock_, reinterpret_cast<struct sockaddr *>(this->sin_), sizeof(struct sockaddr_in)) < 0)
      {
        std::cerr << "Failed." << std::endl;
		return (false);
      }
    else
      {
        std::cerr << "Ok." << std::endl;
		int flag = 1;
		setsockopt(this->sock_, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(flag));
		return (true);
      }
}

void	SocketUnix::listenSocket()
{
    if (listen(this->sock_, this->limFd_) == -1)
        std::cerr << "Failed." << std::endl;
    else
        std::cerr << "Ok." << std::endl;
}

Socket*	SocketUnix::acceptSocket()
{
    sockaddr_in*	csin = new sockaddr_in;

    socklen_t sinsize = sizeof(sockaddr);
    int r;
    Socket* s = NULL;

    if ((r = accept(this->sock_, reinterpret_cast<sockaddr *>(csin), &sinsize)) < 0)
    {
        std::cerr << "error accept" << std::endl;
    }
    else
        s = new SocketUnix(this->port_, this->limFd_, csin, r);
    return s;
}

int		SocketUnix::sendSocket(void* buf, int len)
{
    int r;
    if ((r = send(this->sock_, buf, len, NULL)) < 0)
    {
        std::cerr << "error send" << std::endl;
    }
    return r;
}

int		SocketUnix::recvSocket(void* buf, int len)
{
    int r;
    if ((r = recv(this->sock_, buf, len, NULL)) < 0)
    {
        std::cerr << "error recv" << std::endl;
    }
    return r;
}

void	SocketUnix::close()
{
    ::close(this->getSocket());
}

int	SocketUnix::getSocket()
{
    return this->sock_;
}

int	SocketUnix::getLim()
{
    return this->limFd_;
}
