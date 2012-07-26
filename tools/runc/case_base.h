#ifndef _SNACK_CASE_BASE_H
#define _SNACK_CASE_BASE_H

#include "snack_macro.h"

namespace snack
{
    class CaseBase
    {
        public:
            CaseBase(int id);
            virtual ~CaseBase(){};
            int GetCaseID(){return case_id_;}
            virtual void StartUp();
            virtual void Run();
            virtual void Close();
            virtual void Show()=0;
            void operator()();

            void set_case_id(int id){case_id_ = id;}
        protected:
            int case_id_; 
        private:
    };
}

#endif //_SNACK_CASE_BASE_H
