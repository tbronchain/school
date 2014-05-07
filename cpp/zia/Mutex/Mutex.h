#ifndef MUTEX_H
# define MUTEX_H

# ifdef _WIN32
#  include "MutexWindows.h"
#  define ABSMUTEX MutexWindows
# else
#  include "MutexUnix.h"
#  define ABSMUTEX MutexUnix
# endif // IFDEF WIN_32

#endif // MUTEX_H
