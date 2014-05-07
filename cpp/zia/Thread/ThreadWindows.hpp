#ifndef THREADWINDOWS_HPP_
# define THREADWINDOWS_HPP_

# include <stdio.h>
# include <process.h>
# include <iostream>
# include "Thread.hpp"

template <typename T> class AThread;

template <typename T>
class ThreadWindows : public AThread<T>
{
public:
    ThreadWindows(T& instance, void (T::*pmethodRun)()) :
            AThread<T>(instance, pmethodRun)
    {
        m_thread = (HANDLE)_beginthreadex(NULL, 0, &ThreadWindows::startThread<T>, this, 0, &m_dwThreadId);
    }
    ~ThreadWindows()
    {
        CloseHandle(m_thread);
    }

    template <typename X>
            static unsigned __stdcall startThread(void* vPtr)
    {
        ThreadWindows<X>* ptr = static_cast<ThreadWindows<X> *>(vPtr);
        if (ptr != 0)
        {
            ptr->callBack();
            _endthreadex(0);
        }
        return NULL;
    }

    void callBack()
    {
        this->runMethod();
    }
    void join()
    {
        WaitForSingleObject(this->m_thread, INFINITE);
    }

private:
    void*		m_thread;
    unsigned	m_dwThreadId;
};

#endif // THREADWINDOWS_HPP_
