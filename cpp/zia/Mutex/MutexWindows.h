#ifndef MUTEXWINDOWS_H_
# define MUTEXWINDOWS_H_

//#define WIN32_LEAN_AND_MEAN
# include <WinSock2.h>
# include <Windows.h>

class		 MutexWindows
{
public:
						MutexWindows();
						~MutexWindows();

	void				lock();
	void				unlock();
	bool				tryLock();
	CRITICAL_SECTION&	getMutex();

private:
	CRITICAL_SECTION	mutex_;
};

#endif // MUTEXWINDOWS_H_
