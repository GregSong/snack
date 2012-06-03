#ifndef _RC_SAMPLE_H
#define _RC_SAMPLE_H

#include <map>

#include "case_base.h"
#include "case_macro.h"

using namespace snack;

#define SAMPLE 1 // Case ID

class Sample:public CaseBase
{
    DECLARECASE(Sample, SAMPLE)
    public:
        void Run();
};


#endif // _RC_SAMPLE_H
