#ifndef _SNACK_CASE_MACOR_H
#define _SNACK_CASE_MACOR_H

#define DECLARECASE(a,b) \
    friend class map<int, CaseBase*>; \
    a():CaseBase(b){}; \
    static a * instance_;

#define POSTDECLARECASE(a) \
    a * a::instance_ = new a();

#endif // _SNACK_CASE_MACOR_H
