#ifndef _SNACK_SINGLETON_H
#define _SNACK_SINGLETON_H

template <typename T>
class Singleton
{
    public:
        static T& Instance(){
            static T instance_;
            return instance_;
        }
    private:
};


#endif // _SNACK_SINGLETON_H
