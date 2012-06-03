#include <stdlib.h>
#include <iostream>
#include "snack_macro.h"
#include "case_mgr.h"
using namespace snack;

int main(int argc, char** argv)
{
    int case_id = 0;
    /**
     * argc == 0  --> Run All
     * argc == 1  --> Run case with id 
     **/
    if (argc != 1 && argc != 2)
    {
        std::cerr<<"\033[31mWrong Argument\033[m"<<std::endl;
        return SNACK_FAILURE;
    }

    if (argc == 2)
    {
        case_id = atoi(argv[1]);
        CaseMgr::Instance().Run(case_id);
    } else {
        CaseMgr::Instance().RunAll();
    }

    return SNACK_SUCCESS;
}

