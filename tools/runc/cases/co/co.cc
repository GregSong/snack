#include <iostream>
using namespace std;
#include "co.h"
#include "coroutine.h"
using namespace snack;

POSTDECLARECASE(Co)

void Call2Two()
{
    cout<<"Hi Greg"<<endl;
    Coroutine::Yield();
    cout<<"Yes, it's delicious!"<<endl;
    Coroutine::Yield();
    cout<<"OK"<<endl;
}

void Call2One()
{
    Coroutine& co = Coroutine::Create(Call2Two);
    cout<<"Hi Jimmy"<<endl;
    co.Resume();
    cout<<"Did you have breakfast?"<<endl;
    co.Resume();
    cout<<"Great! Let's start working"<<endl; 
    co.Resume();
}

void Co::Run()
{
    cout<<"Co::Run"<<endl;
    Coroutine & co = Coroutine::Create(Call2One);
    cout<<"Jimmy and Greg meet each other in office"<<endl;
    co.Resume();
    cout<<"They are back to work"<<endl;
    return;
}


void Co::Show()
{
    cout<<"case id: "<<case_id_<<"\t"<<CO_DESC<<endl;
}
