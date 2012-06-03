#include "coroutine.h"

namespace snack
{
    ucontext_t Coroutine::caller_;
    ucontext_t Coroutine::callee_;
    Coroutine& Coroutine::Create(Function fun,...)
    {
        Coroutine* pco = new Coroutine();
        getcontext(&pco->context_);
        pco->context_.uc_stack.ss_sp = pco->stack_;
        pco->context_.uc_stack.ss_size = STACK_SIZE;
        pco->context_.uc_link = 0;
        makecontext(&pco->context_, fun, 0);
        return *pco;
    }

    void Coroutine::Resume()
    {
        ucontext_t save = caller_;
        context_.uc_link = &caller_;
        swapcontext(&caller_, &context_);
        context_ = callee_;
        caller_ = save;
    }
    void Coroutine::Yield()
    {
        swapcontext(&callee_, &caller_);
    }
}
