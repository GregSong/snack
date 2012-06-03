#include <iostream>
#include "case_base.h"
#include "case_mgr.h"

namespace snack
{ 
    CaseBase::CaseBase(int id):case_id_(id)
    {
        CaseMgr::Instance().Register(this);
    }
    void CaseBase::operator()()
    {
        StartUp();
        Run();
        Close();
    }

    void CaseBase::StartUp()
    {
        std::cout<<"CaseBase::StartUp"<<std::endl;
        return;
    }

    void CaseBase::Run()
    {
        std::cout<<"CaseBase::Run"<<std::endl;
        return;
    }

    void CaseBase::Close()
    {
        std::cout<<"CaseBase::Close"<<std::endl;
        return;
    } 
}
