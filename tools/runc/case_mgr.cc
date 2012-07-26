#include <iostream>
#include <algorithm>
using namespace std;

#include "case_utils.h"
#include "case_mgr.h"
#include "case_base.h"


namespace snack
{
    void CaseMgr::Register(CaseBase *c)
    {
        int id = c->GetCaseID();
        do
        {
            if ( cases_.find(id) == cases_.end())
            {
                c->set_case_id(id);
                cases_.insert(pair<int, CaseBase*>(id, c));
                break;
            } else {
                // Todo: I will build my log system later on
#ifdef _DEBUG_
                std::cout<<"Duplicate Case: "<<id<<std::endl;
#endif // _DEBUG_
                id++;
            } 
        }while(1);
        return;
    } 
    void CaseMgr::ShowAll()
    {
        for_each(cases_.begin(), cases_.end(), ShowCase());
    }

    void CaseMgr::Run(int id)
    { 
        if ( cases_.find(id) != cases_.end())
        {
            (*cases_[id])();
        } else {
            std::cout<<" No such case !"<<std::endl;
        } 
    }

    void CaseMgr::RunAll()
    {
        for_each(cases_.begin(), cases_.end(), RunCase());
    }
}
