#ifndef _SNACK_CASE_UTILS_H
#define _SNACK_CASE_UTILS_H

#include <map>
using namespace std;

#include "case_base.h"

namespace snack
{
    // Functor to call case 
    class RunCase
    {
        public:
            void operator()(pair<const int, CaseBase*> &c)
            {
                (*c.second)();
            }

    };

    class ShowCase
    {
        public:
            void operator()(pair<const int, CaseBase*> &c)
            {
                (*c.second).Show();
            }
    };
}

#endif // _SNACK_CASE_UTILS_H
