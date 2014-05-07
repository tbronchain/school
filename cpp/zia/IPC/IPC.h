 #ifndef IPC_H
# define IPC_H

#define RANGE_START 8080
namespace IPC
{

    enum CMD
    {
        STOP_CLEAN = 'a',
        STOP_FORCE = 'b',
        RELOAD_CLEAN = 'c',
        RELOAD_FORCE = 'd',
        IERROR = 'z'
    };
};



# ifdef _WIN32
#  include "IPCWindows.h"
#  define ABSIPC IPCWindows
# else
#  include "IPCUnix.h"
#  define ABSIPC IPCUnix
# endif



#endif // IPC_CMD
