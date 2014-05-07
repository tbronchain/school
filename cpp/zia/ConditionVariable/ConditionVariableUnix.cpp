#include "ConditionVariableUnix.h"
#include "ConditionSleep.h"
#include <iostream>

ConditionVariableUnix::ConditionVariableUnix() : condition_(AWAKE)
{
    pthread_cond_init(&this->c_, NULL);
}

ConditionVariableUnix::~ConditionVariableUnix()
{
  pthread_cond_destroy(&this->c_);
}

void	ConditionVariableUnix::WakeCond()
{
    this->mutex_.lock();
    if (this->condition_ == SLEEPING)
    {
        this->condition_ = ORDER_AWAKE;
        pthread_cond_signal(&this->c_);
    }
    this->mutex_.unlock();
}

void	ConditionVariableUnix::SleepCond()
{
    this->mutex_.lock();
    this->condition_ = SLEEPING;
    while (this->condition_ == SLEEPING)
        pthread_cond_wait(&this->c_, &(this->mutex_.getMutex()));
    this->condition_ = AWAKE;
    this->mutex_.unlock();
}





void	ConditionVariableUnix::WakeCond(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked)
{
    mHandshaked.lock();
    if (this->condition_ == SLEEPING)
    {
        this->condition_ = ORDER_AWAKE;
        pthread_cond_signal(&this->c_);

        //
        handshaked.SleepCondHandshakedMaster(mHandshaked);
        //
    }
    else
      std::cout << "CODE RRR" << std::endl;
    mHandshaked.unlock();
}

void	ConditionVariableUnix::orderSleepCondHandshaked(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked)
{

    mHandshaked.lock();
    if (this->condition_ == AWAKE)
    {
        this->condition_ = ORDER_SLEEP;
        handshaked.SleepCondHandshakedMaster(mHandshaked);
    }
    else
      std::cout << "CODE RRR" << std::endl;
    mHandshaked.unlock();
}


/*called*/
void	ConditionVariableUnix::WakeCondHandshaked()
{
    if (this->condition_ == SLEEPING)
    {
        this->condition_ = ORDER_AWAKE;
        pthread_cond_signal(&this->c_);
    }
    else
      std::cout << "CODE RRR" << std::endl;
}

void	ConditionVariableUnix::SleepCondHandshakedSlave(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked)
{
    mHandshaked.lock();
    if (this->condition_ == ORDER_SLEEP)
    {
        this->condition_ = SLEEPING;

        handshaked.WakeCondHandshaked();
        while (this->condition_ != ORDER_AWAKE)
            pthread_cond_wait(&this->c_, &mHandshaked.getMutex());
        this->condition_ = AWAKE;
      /**/
        handshaked.WakeCondHandshaked();
      /**/
    }
    mHandshaked.unlock();
}

void	ConditionVariableUnix::SleepCondHandshakedMaster(ABSMUTEX& mHandshaked)
{
    this->condition_ = SLEEPING;
    while (this->condition_ != ORDER_AWAKE)
        pthread_cond_wait(&this->c_, &mHandshaked.getMutex());
    this->condition_ = AWAKE;
}
