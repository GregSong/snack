#include <iostream>
using namespace std;

#include "sn_time.h"
using namespace snack;

int main(int argc, char** argv)
{ 
    SNTime now = SNTime::Now();
    now.SetTimeZone(CCT);
    now.Print();

    String str = now.GetString("[$YY-$MA-$DS]");
    cout<<str<<endl;
    return 0;
}
