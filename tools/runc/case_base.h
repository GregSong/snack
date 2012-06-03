#ifndef _CASE_BASE_H
#define _CASE_BASE_H


namespace snack
{
    class CaseBase
    {
        public:
            CaseBase(int id);
            int GetCaseID(){return case_id_;}
            virtual void StartUp();
            virtual void Run();
            virtual void Close();
            void operator()();
        private:
            int case_id_; 
    };
}

#endif //_CASE_BASE_H
