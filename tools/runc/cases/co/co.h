#ifndef _RC_CO_H
#define _RC_CO_H

#include <map>

#include "case_base.h"
#include "case_macro.h"

using namespace snack;

#define CO 2 // Case ID

class Co:public CaseBase
{
    DECLARECASE(Co, CO)
    public:
        void Run();
};


#endif // _RC_CO_H
