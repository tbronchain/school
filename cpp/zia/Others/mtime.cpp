//

#include "mtime.h"

#ifdef _WIN32

int		gettimeofday(timeval *tp, void*)
{
	_timeb timebuffer;
	_ftime_s(&timebuffer);
	tp->tv_sec = static_cast<int>(timebuffer.time);
	tp->tv_usec = static_cast<int>(timebuffer.millitm * 1000);
	return 0;
}

#endif

void	getTime(timeval* t, int pause, bool actual)
{
	if (actual)
		gettimeofday(t, NULL);
	if (pause)
	{
		t->tv_sec = static_cast<int>((t->tv_sec) + (pause / 1000) + (((t->tv_usec) + (pause % 1000) * 1000) / 1000000));
		t->tv_usec = static_cast<int>((t->tv_usec + pause * 1000) % 1000000);
	}
}
