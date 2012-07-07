#ifndef _SNACK_OPTION_H
#define _SNACK_OPTION_H

#include "option_impl.h"
#define OPTION2(x,y) x##y
#define OPTION1(x,y) OPTION2(x,y)
#define OPTION Option OPTION1(opt, __LINE__)


#endif // _SNACK_OPTION_H
