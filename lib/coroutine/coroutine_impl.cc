#include "snack_macro.h"
#include "coroutine.h"

namespace snack
{
    ucontext_t Coroutine::caller;
    ucontext_t Coroutine::callee;
    bool       Coroutine::first_run = TRUE;
    Coroutine& Coroutine::Create(Function fun,...)
    {
        Coroutine* pco = new Coroutine(fun);
        getcontext(&pco->context_);
        pco->context_.uc_stack.ss_sp = pco->stack_;
        pco->context_.uc_stack.ss_size = STACK_SIZE;

        return *pco;
    }

    void Coroutine::Resume()
    { 
        if ( first_run )
        {
          first_run = FALSE;
          getcontext(&caller);
        }

        if ( status_ == NEW)
        {
          context_.uc_link = &caller;

          makecontext(&context_, fun_, 0);
          status_ = RUNNING;
        }

        ucontext_t save = caller;
        swapcontext(&caller, &context_);
        context_ = callee;
        caller = save;
    }

    void Coroutine::Yield()
    {
        swapcontext(&callee, &caller);
    }
}
