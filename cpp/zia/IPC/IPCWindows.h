 #ifndef IPCWINDOWS_H
# define IPCWINDOWS_H

#include <winsock2.h>
#include <windows.h>
#include <io.h>
#include <iostream>

#include <assert.h>
#include <stdio.h>


#include "SocketWindows.h"
#include "IPC.h"
class IPCWindows
{
public:
IPCWindows(int);
~IPCWindows();
IPC::CMD read();
void write(IPC::CMD);
int getReadFd();
int getWriteFd();
private:
	int nbPort_; 
SocketWindows *fdRead_;
SocketWindows *fdWriteMaster_;
SocketWindows *fdWrite_;
};

#endif // IPCWINDOWS_H
