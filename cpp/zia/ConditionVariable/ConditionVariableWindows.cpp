//

//#include <winsock2.h>
//#include <windows.h>
#include <iostream>
#include "ConditionSleep.h"
#include "ConditionVariableWindows.h"


ConditionVariableWindows::ConditionVariableWindows() : condition_(AWAKE)
{
	InitializeConditionVariable(&this->c_);
}

ConditionVariableWindows::~ConditionVariableWindows()
{
}

void	ConditionVariableWindows::WakeCond()
{
	this->mutex_.lock();
	if (this->condition_ == SLEEPING)
	{
		this->condition_ = ORDER_AWAKE;
		WakeConditionVariable(&this->c_);
	}
	this->mutex_.unlock();
}

void	ConditionVariableWindows::SleepCond()
{
	this->mutex_.lock();
	if (this->condition_ == ORDER_SLEEP)
	{
		this->condition_ = SLEEPING;
		while (this->condition_ == SLEEPING)
			SleepConditionVariableCS(&this->c_, &(this->mutex_.getMutex()), INFINITE);
		this->condition_ = AWAKE;
	}
	this->mutex_.unlock();
}

void	ConditionVariableWindows::orderSleepCond()
{
	this->mutex_.lock();
	this->condition_ = ORDER_SLEEP;
	this->mutex_.unlock();
}

void	ConditionVariableWindows::WakeCond(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked)
{
	mHandshaked.lock();
	if (this->condition_ == SLEEPING)
	{
		this->condition_ = ORDER_AWAKE;
		WakeConditionVariable(&this->c_);
		handshaked.SleepCondHandshakedMaster(mHandshaked);
	}
	mHandshaked.unlock();
}

void	ConditionVariableWindows::orderSleepCondHandshaked(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked)
{

	mHandshaked.lock();
	if (this->condition_ == AWAKE)
	{
		this->condition_ = ORDER_SLEEP;
		handshaked.SleepCondHandshakedMaster(mHandshaked);
	}
	mHandshaked.unlock();
}

void	ConditionVariableWindows::WakeCondHandshaked()
{
	if (this->condition_ == SLEEPING)
	{
		this->condition_ = ORDER_AWAKE;
		WakeConditionVariable(&this->c_);
	}
}

void	ConditionVariableWindows::SleepCondHandshakedSlave(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked)
{
	mHandshaked.lock();
	if (this->condition_ == ORDER_SLEEP)
	{
		this->condition_ = SLEEPING;

		handshaked.WakeCondHandshaked();
		while (this->condition_ != ORDER_AWAKE)
			SleepConditionVariableCS(&this->c_, &mHandshaked.getMutex(), INFINITE);
		this->condition_ = AWAKE;
		handshaked.WakeCondHandshaked();
	}
	mHandshaked.unlock();
}

void	ConditionVariableWindows::SleepCondHandshakedMaster(ABSMUTEX& mHandshaked)
{
	this->condition_ = SLEEPING;
	while (this->condition_ != ORDER_AWAKE)
		SleepConditionVariableCS(&this->c_, &mHandshaked.getMutex(), INFINITE);
	this->condition_ = AWAKE;
}
