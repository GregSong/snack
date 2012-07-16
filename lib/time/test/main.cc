#include <iostream>
using namespace std;

#include "sn_time.h"
using namespace snack;

int main(int argc, char** argv)
{ 
    SNTime now = SNTime::Now();
    now.SetTimeZone(CCT);
    now.Print();

    String str = now.GetString("[$YY-$MA-$DS $WS CCT $H2:$MI:$SS]");
    cout<<str<<endl;
    
    str = now.GetString("[$Y2-$MD-$DD $WD $ZS $H1:$MI:$SS]");
    cout<<str<<endl;
    return 0;
}
