#ifndef CONDITION_VARIABLE_H
# define CONDITION_VARIABLE_H

# ifdef _WIN32
#  include "ConditionVariableWindows.h"
#  define ABSCONDITION ConditionVariableWindows
# else
#  include "ConditionVariableUnix.h"
#  define ABSCONDITION ConditionVariableUnix
# endif


#endif // CONDITION_VARIABLE_H
