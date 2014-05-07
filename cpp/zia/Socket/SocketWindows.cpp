//

#include <iostream>
#include <WinSock2.h>
#include "SocketWindows.h"


SocketWindows::SocketWindows(int port, int limFd, SOCKADDR_IN* sin, SOCKET sock)
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

SocketWindows::~SocketWindows()
{
	if (shutdown(this->sock_, SD_BOTH) == SOCKET_ERROR)
		std::cerr << "shutdown error" << std::endl;
	if (closesocket(this->sock_) == SOCKET_ERROR)
		std::cerr << "close error" << std::endl;
	delete this->sin_;
}

void	SocketWindows::createSocket()
{
	if (WSAStartup(MAKEWORD(2, 0), &this->WSAData_))
		std::cerr << "WSAStartup Failed." << std::endl;
	else
		std::cerr << "WSAStartup OK." << std::endl;

	this->sin_ = new SOCKADDR_IN;
	memset(this->sin_, 0, sizeof(*(this->sin_)));
	
	this->sin_->sin_addr.s_addr	= INADDR_ANY;
	this->sin_->sin_family		= AF_INET;
	this->sin_->sin_port		= htons(this->port_);

	if ((this->sock_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		std::cerr << "Socket Failed." << std::endl;
	else
	{
		std::cerr << "Socket Ok." << std::endl;
	}
}

bool	SocketWindows::bindSocket()
{
        if (bind(this->sock_, reinterpret_cast<SOCKADDR *>(this->sin_), sizeof(SOCKADDR)) == SOCKET_ERROR)
        {
                std::cerr << "Bind Failed : " << WSAGetLastError() << std::endl;
                return false;
        }
        else
        {
                std::cerr << "Bind Ok." << std::endl;
                int flag = 1;
                setsockopt(this->sock_, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(flag));
                return true;
        }
}


void	SocketWindows::listenSocket()
{
	if (listen(this->sock_, this->limFd_) == SOCKET_ERROR)
		std::cerr << "Listen Failed : " << WSAGetLastError() << std::endl;
	else
		std::cerr << "Listen Ok." << std::endl;
}

Socket*	SocketWindows::acceptSocket()
{
	SOCKADDR_IN*	csin = new SOCKADDR_IN;

	int sinsize = sizeof(SOCKADDR);
	SOCKET r;
	Socket* s = NULL;

	// STEP_IN
	if ((r = WSAAccept(this->sock_, reinterpret_cast<SOCKADDR *>(csin), &sinsize, NULL, NULL)) == INVALID_SOCKET)
	{
		std::cerr << "error accept" << std::endl;
	}
	else
	{
		s = new SocketWindows(this->port_, this->limFd_, csin, r);
	}
	return s;
}

void	SocketWindows::connectSocket()
{
    this->sin_->sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(this->sock_, (struct sockaddr *)(this->sin_), sizeof(struct sockaddr)) != 0)
		std::cerr << "error connection" << std::endl;
}

int		SocketWindows::sendSocket(void* buf, int len)
{
	int r;
	if ((r = send(this->sock_, static_cast<char*>(buf), len, NULL)) < 0)
	{
		std::cerr << "error send" << std::endl;
	}
	return r;
}

int		SocketWindows::recvSocket(void* buf, int len)
{
	int r;
	if ((r = recv(this->sock_, static_cast<char*>(buf), len, NULL)) < 0)
	{
		std::cerr << "error recv" << std::endl;
	}
	return r;
}

void	SocketWindows::close()
{
	closesocket(this->getSocket());
}

int		SocketWindows::getSocket()
{
	return this->sock_;
}

int		SocketWindows::getLim()
{
	return this->limFd_;
}
