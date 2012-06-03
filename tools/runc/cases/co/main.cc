#include "snack_macro.h"
#include "case_mgr.h"

#include "co.h"

int main(int argc, char ** argv)
{
    CaseMgr::Instance().Run(CO);
    return SNACK_SUCCESS;
}
