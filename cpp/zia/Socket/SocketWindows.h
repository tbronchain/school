#ifndef SOCKETWINDOWS_H_
# define SOCKETWINDOWS_H_

# include "Socket.h"

class Socket;

class SocketWindows : virtual public Socket
{
public:
    SocketWindows(int port, int limFd = 102400, SOCKADDR_IN* sin = NULL, SOCKET sock = 0);
    ~SocketWindows();

    void    		createSocket();
    bool    		bindSocket();
    void    		listenSocket();
    void    		close();
    void                connectSocket();
    Socket* 		acceptSocket();
    int			sendSocket(void* buf, int len);
    int			recvSocket(void* buf, int len);
    int			getSocket();
    int			getLim();

private:
    int			port_;
    int			limFd_;
    SOCKADDR_IN* sin_;
    SOCKET		sock_;
    WSADATA		WSAData_;
};

#endif // SOCKETWINDOWS_H_
