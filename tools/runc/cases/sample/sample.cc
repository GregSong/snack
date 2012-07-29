#include <iostream>
using namespace std;
#include "sample.h"

POSTDECLARECASE(Sample)

void Sample::Run()
{
    cout<<"Sample::Run"<<endl;
    return;
}

void Sample::Show()
{
    cout<<"case id: "<<case_id_<<"\t"<<SAMPLE_DESC<<endl;
}

