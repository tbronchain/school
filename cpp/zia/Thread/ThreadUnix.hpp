#ifndef THREADUNIX_HPP_
# define THREADUNIX_HPP_

# include <iostream>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "Thread.hpp"

template <typename T> class AThread;

template <typename T>
        class ThreadUnix : public AThread<T>
{
public:
    ThreadUnix(T& instance, void (T::*pmethodRun)()) :
            AThread<T>(instance, pmethodRun)
    {
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        if (pthread_create(&m_thread_,&attr, startThread, (void *)this) == -1)
            perror("Thread: create failed");
    }
    ~ThreadUnix()
    {
        pthread_attr_destroy(&attr);
    }

    static void* startThread(void *vPtr)
    {

        ThreadUnix *ptr = (ThreadUnix *)vPtr; // change dynamic
        ptr->CALLBACKW();
        pthread_exit(NULL);
    }
    void CALLBACKW()
    {
        this->runMethod();
    }
    void join()
    {
        pthread_join(this->m_thread_, NULL);
    }

private:
    pthread_t		m_thread_;
    pthread_attr_t	attr;
};

#endif // THREADUNIX_HPP_
