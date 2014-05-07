#ifndef IPCUNIX_H
# define IPCUNIX_H


#include "IPC.h"

class IPCUnix
{
public:
    IPCUnix(unsigned int);
    ~IPCUnix();
    IPC::CMD read();
    void write(IPC::CMD);
    int getReadFd() const;
    int getWriteFd() const;
private:
    int fdRead_;
    int fdWrite_;
};

#endif // IPCUNIX_H
