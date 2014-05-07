#include "MutexUnix.h"
#include <iostream>

MutexUnix::MutexUnix()
{
	pthread_mutex_init(&(this->_mut), NULL);
}


MutexUnix::~MutexUnix()
{
	pthread_mutex_destroy(&(this->_mut));
}

void		MutexUnix::lock()
{
    pthread_mutex_lock(&(this->_mut));
}

pthread_mutex_t& MutexUnix::getMutex()
{
    return this->_mut;
}

void		MutexUnix::unlock()
{
	pthread_mutex_unlock(&(this->_mut));
}

bool		MutexUnix::tryLock()
{
    if (pthread_mutex_trylock(&(this->_mut)) == 0)
        return true;
    return false;
}
