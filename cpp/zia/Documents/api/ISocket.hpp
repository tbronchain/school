#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class ISocket
	* \brief interface that describes the socket methods
	*/
	class	ISocket
	{
	public:
		virtual				~ISocket() {};
	/**
	* \fn void bindSocket ()
	* \brief bind a socket on a port
	* \return void
	*/
		virtual void		bindSocket() = 0;
	/**
	* \fn void listenSocket ()
	* \brief listen on a port for connexions
	*
	* \return void
	*/
		virtual void		listenSocket() = 0;
	/**
	* \fn Socket* acceptSocket ()
	* \brief accept a new client on the socket
	*
	* \return Socket* return a socket class for the new client
	*/
		virtual Socket*		acceptSocket() = 0;
	/**
	* \fn int sendSocket (void* buf, int len)
	* \brief write on a socket
	*
	* \param buf buffer which contain the datas to send
	* \param len size of the buf parameter
	* \return int number of bytes sent
	*/
		virtual int			sendSocket(void* buf, int len) = 0;
	/**
	* \fn int recvSocket (void* buf, int len)
	* \brief read on a socket
	*
	* \param buf buffer which contain the datas read
	* \param len size of the buf parameter
	* \return int number of bytes read
	*/
		virtual int			recvSocket(void* buf, int len) = 0;
	/**
	* \fn int getSocket ()
	* \brief return the socket
	* \return int return the socket
	*/
		virtual int			getSocket() = 0;
	/**
	* \fn int getLim ()
	* \brief return the limit of FD
	* \return int return the limit of FD
	*/
		virtual int			getLim() = 0;
	};
}
