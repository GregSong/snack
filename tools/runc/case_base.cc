#include <iostream>
#include "case_base.h"
#include "case_mgr.h"

namespace snack
{ 
    CaseBase::CaseBase(int id):case_id_(id)
    {
#ifdef _DEBUG_
        cout<<"CaseBase::CaseBase"<<endl;
#endif // _DEBUG_
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
#ifdef _DEBUG_
        std::cout<<"CaseBase::StartUp"<<std::endl;
#endif // _DEBUG_
        return;
    }

    void CaseBase::Run()
    {
#ifdef _DEBUG_
        std::cout<<"CaseBase::Run"<<std::endl;
#endif // _DEBUG_
        return;
    }

    void CaseBase::Close()
    {
#ifdef _DEBUG_
        std::cout<<"CaseBase::Close"<<std::endl;
#endif // _DEBUG_
        return;
    } 

    void CaseBase::Show()
    {
#ifdef _DEBUG_
        std::cout<<"CaseBase::Show"<<std::endl;
#endif // _DEBUG_
        return;
    }
}
