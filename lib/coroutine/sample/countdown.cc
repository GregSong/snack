#include <iostream>
#include <map>
using namespace std;

#include "case_macro.h"
#include "case_base.h"
#include "coroutine.h"

using namespace snack;

#define COUNTDOWN 1 // Case ID

class CountDown:public CaseBase
{
    DECLARECASE(CountDown, COUNTDOWN)
    public:
        void Run();
};

POSTDECLARECASE(CountDown);

int counter = 0;
void countdown()
{
    while (counter > 0)
    {
        counter--;
        Coroutine::Yield();
    }
}
void CountDown::Run()
{
    cout<<"CountDown::Run"<<endl;
    Coroutine& co = Coroutine::Create(countdown);
    counter = 10;
    do
    {
        co.Resume();
        // use counter
        cout<<"Counter: "<<counter<<endl;
    }while (counter>0);
        
    return;
}
