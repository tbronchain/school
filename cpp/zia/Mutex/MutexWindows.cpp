//

#include "MutexWindows.h"

MutexWindows::MutexWindows()
{
	InitializeCriticalSection(&(this->mutex_));
}

MutexWindows::~MutexWindows()
{
	DeleteCriticalSection(&(this->mutex_));
}

void		MutexWindows::lock()
{
	EnterCriticalSection(&(this->mutex_));
}

CRITICAL_SECTION& MutexWindows::getMutex()
{
	return this->mutex_;
}

void		MutexWindows::unlock()
{
	LeaveCriticalSection(&(this->mutex_));
}

bool		MutexWindows::tryLock()
{
	return (TryEnterCriticalSection(&(this->mutex_)) ? true : false);
}
