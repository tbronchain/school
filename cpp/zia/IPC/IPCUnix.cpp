#include <unistd.h>
#include <iostream>

#include "IPCUnix.h"

IPCUnix::IPCUnix(unsigned int)
{
    this->fdRead_ = 0;
    this->fdWrite_ = 0;
    int fd[2];

   if (pipe(fd) != -1)
    {
        this->fdRead_ = fd[0];
        this->fdWrite_ = fd[1];
    }
    else
    {
        std::cout << "Pipe creation FAILED..." << std::endl;
    }
}

IPC::CMD IPCUnix::read()
{
    char unlock = IPC::IERROR;
    int nbread = ::read(this->fdRead_, &unlock, 1);
    if (nbread < 0)
        unlock = IPC::IERROR;
    return static_cast<IPC::CMD>(unlock);
}

void IPCUnix::write(IPC::CMD cmd)
{ 
    char unblock = static_cast<char>(cmd);
    ::write(this->fdWrite_, &unblock , 1);
}

int IPCUnix::getReadFd() const
{
    return this->fdRead_;
}

int IPCUnix::getWriteFd() const
{
    return this->fdWrite_;
}

IPCUnix::~IPCUnix()
{
    close(this->fdRead_);
    close(this->fdWrite_);
}
