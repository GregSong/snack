#ifndef _RC_CO_H
#define _RC_CO_H

#include <map>

#include "case_base.h"
#include "case_macro.h"

using namespace snack;

#define CO 2 // Case ID
#define CO_DESC "Test Coroutine"

class Co:public CaseBase
{
    DECLARECASE(Co, CO)
    public:
        void Run();
        void Show();
};


#endif // _RC_CO_H
