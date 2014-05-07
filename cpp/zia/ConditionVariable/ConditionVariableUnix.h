#ifndef CONDITION_VARIABLE_UNIX_H_
# define CONDITION_VARIABLE_UNIX_H_

#include "Mutex.h"

class ConditionVariableUnix
{
public:
        ConditionVariableUnix();
        ~ConditionVariableUnix();
        void	SleepCond();
        void	WakeCond();


        void	WakeCond(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked);
        void	orderSleepCondHandshaked(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked);
        void	WakeCondHandshaked();
        void	SleepCondHandshakedSlave(ConditionVariableUnix& handshaked, ABSMUTEX& mHandshaked);
        void	SleepCondHandshakedMaster(ABSMUTEX& mHandshaked);

private:
        int				condition_;
        pthread_cond_t	c_;
        ABSMUTEX 		mutex_;
};

#endif // CONDITION_VARIABLE_UNIX_H_
