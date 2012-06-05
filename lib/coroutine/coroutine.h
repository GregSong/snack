#ifndef _SNACK_COROUTINE_H
#define _SNACK_COROUTINE_H

#include <ucontext.h>

#define STACK_SIZE 2048

namespace snack
{
    class Coroutine
    {
        public:
            typedef void (*Function)(void);
            void Resume();
            static Coroutine& Create(Function, ...);
            static void Yield();
        private:
            Coroutine(){}
            Coroutine(const Coroutine&){}
            Coroutine& operator=(const Coroutine&){}
            char stack_[STACK_SIZE];
            ucontext_t context_;

            static ucontext_t caller_;
            static ucontext_t callee_;
    };
}

#endif // _SNACK_COROUTINE_H
