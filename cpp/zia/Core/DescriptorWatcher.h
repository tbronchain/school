#ifndef DESCRIPTORWATCHER_H_
# define DESCRIPTORWATCHER_H_

# ifdef _WIN32
#  include <winsock2.h>
#  include <windows.h> 
#  define ABSPOLL WSAPoll
#  define ABSPOLLTABLE WSAPOLLFD
# else
#  include <poll.h>
#  define ABSPOLL poll
#  define ABSPOLLTABLE struct pollfd
# endif // _WIN32

# include <deque>
# include "DescriptorConf.h"

class DescriptorWatcher
{
public:
    DescriptorWatcher(unsigned int);
    ~DescriptorWatcher();

    std::deque<DescriptorConf>&                         getAskDeque();
    std::deque<DescriptorConf>&                         getReadyDeque();
    void						watch(int timeout = -1);

private:
    void						build();
    void						unBuild();
    void						resetDescriptorConfDeque(std::deque<DescriptorConf>&);
    int							currDescNb_;
    unsigned int                        		descMax_;
    ABSPOLLTABLE*                       		pollTable_;
    std::deque<DescriptorConf>                          askDescriptors_;
    std::deque<DescriptorConf>                          readyDescriptors_;
};

#endif // DESCRIPTORWATCHER_H
