#ifndef CONDITION_VARIABLE_WINDOWS_H_
# define CONDITION_VARIABLE_WINDOWS_H_
#include "Mutex.h"

class ConditionVariableWindows
{
public:
        ConditionVariableWindows();
        ~ConditionVariableWindows();
        void	SleepCond();
        void	WakeCond();
		void	orderSleepCond();
		
void	WakeCond(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked);
void	orderSleepCondHandshaked(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked);
void	WakeCondHandshaked();
void	SleepCondHandshakedSlave(ConditionVariableWindows& handshaked, ABSMUTEX& mHandshaked);
void	SleepCondHandshakedMaster(ABSMUTEX& mHandshaked);
private:
        int				condition_;
        CONDITION_VARIABLE	c_;
        ABSMUTEX 		mutex_;
};

#endif // CONDITION_VARIABLE_WINDOWS_H_
