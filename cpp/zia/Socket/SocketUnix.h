#ifndef SOCKETUNIX_H_
# define SOCKETUNIX_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "Socket.h"

class SocketUnix : virtual public Socket
{
public:
			SocketUnix(int port, int limFd = 1024, sockaddr_in* sin = NULL, int = 0);
			~SocketUnix();

	void	createSocket();
	bool	bindSocket();
	void	listenSocket();
	Socket*	acceptSocket();
	int		sendSocket(void* buf, int len);
	int		recvSocket(void* buf, int len);
	void	close();
	int		getSocket();
	int		getLim();

private:
	int				port_;
	int				limFd_;
	sockaddr_in*	sin_;
	int				sock_;
};

#endif // SOCKETUNIX_H_
