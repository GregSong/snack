#ifndef _SNACK_CASE_MGR_H
#define _SNACK_CASE_MGR_H

#include <map>

using namespace std;

namespace snack
{
    class CaseBase;
    class CaseMgr
    {
        public:
            static CaseMgr& Instance(){
                static CaseMgr instance_; 
                return instance_;
            }
            void Register(CaseBase* c);
            void Run(int i);
            void RunAll(); 
        private:
            typedef std::map<int, CaseBase*> CASES;
            CaseMgr(){};
            CaseMgr(const CaseMgr&){}
            CaseMgr& operator=(const CaseMgr&){}

            CASES cases_;
    };
}

#endif // _SNACK_CASE_MGR_H
