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
        if ( cases_.find(id) == cases_.end())
        {
            cases_.insert(pair<int, CaseBase*>(id, c));
        } else {
            // Todo: I will build my log system later on
            std::cout<<"Duplicate Case: "<<id<<std::endl;
        }
        return;
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
