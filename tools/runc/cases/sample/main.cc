#include "snack_macro.h"
#include "case_mgr.h"

#include "sample.h"

int main(int argc, char ** argv)
{
    CaseMgr::Instance().Run(SAMPLE);
    return SNACK_SUCCESS;
}
