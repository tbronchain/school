#ifndef MUTEXUNIX_H_
# define MUTEXUNIX_H_

# include <pthread.h>

class		MutexUnix
{
public:
						MutexUnix();
						~MutexUnix();

	void				lock();
	void				unlock();
	bool				tryLock();
	pthread_mutex_t&	getMutex();

private:
	pthread_mutex_t		_mut;
};

#endif // MUTEXUNIX_H_
