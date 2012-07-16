#ifndef _SNACK_MANAGER_H
#define _SNACK_MANAGER_H

namespace snack
{
    template< typename T1, typename T2>
        class Manager:public Singleton<Manger<T1, T2>>
    {
        public:
            Manager(){};
            virual ~Manager(){}
            void Register(const T1& key, const T2& value);
            map<T1,T2>::interator& operator[](const T1& key);

        private:
            map<T1,T2> members_;
    };

#include "sn_manager.cc"
}

#endif // _SNACK_MANAGER_H

