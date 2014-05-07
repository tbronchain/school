#ifndef MTIME_H_
# define MTIME_H_

# include <ctime>

# ifdef _WIN32
#  include <WinSock2.h>
#  include <Windows.h>
#  include <sys/timeb.h>
#  define msleep(x) Sleep(x)
# else
#  include <unistd.h>
#  include <cstdlib>
#  include <sys/time.h>
#  define msleep(x) usleep(x*1000)
# endif // !_WIN32

void	getTime(timeval*, int pause = 0, bool actual = true);

#endif // !SLEEP_H_
