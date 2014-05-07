#include <io.h>
#include "IPCWindows.h"

IPC::CMD IPCWindows::read()
{
	char unlock = IPC::IERROR;
	this->fdRead_->recvSocket(&unlock, 1);
	return static_cast<IPC::CMD>(unlock);
}

void IPCWindows::write(IPC::CMD cmd)
{
	char unblock = static_cast<char>(cmd);    
	this->fdWrite_->sendSocket(&unblock, 1);
}

int IPCWindows::getReadFd()
{
	return (this->fdRead_->getSocket());
}

int IPCWindows::getWriteFd()
{
	return (this->fdWrite_->getSocket());
}

IPCWindows::~IPCWindows()
{
	delete this->fdRead_;
	delete this->fdWriteMaster_;
	delete this->fdWrite_;
}

IPCWindows::IPCWindows(int nbPort) : 
nbPort_(nbPort)
{
	/*serv*/
	bool loopOnPort = true;
	while (true)
	{
		this->fdWriteMaster_ = new SocketWindows(this->nbPort_);
		if (this->fdWriteMaster_->bindSocket())
			break;
		else
		{
			delete this->fdWriteMaster_;
			this->nbPort_++;
		}
	}
	this->fdWriteMaster_->listenSocket();

	/*cli*/
	this->fdRead_ = new SocketWindows(this->nbPort_);
	this->fdRead_->connectSocket();

	this->fdWrite_ = dynamic_cast<SocketWindows *>(this->fdWriteMaster_->acceptSocket());

}

