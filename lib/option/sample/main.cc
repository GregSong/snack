#include <iostream>
#include "snack_macro.h"
#include "snack_types.h"
#include "option.h"

using namespace snack;

Strings args;
OPTION("help",'h',Option::BOOL,"false","Usage information");
OPTION("dir",'d',Option::STRING,"./","Searching dir");
OPTION("debug", CEMPTY, Option::INT, "1","Debug level");
OPTION("param", 'p', Option::ARRAY);
OPTION("version", 'v', Option::BOOL);

int main(int argc, char** argv)
{
    // Obviously option object should recv argc and argv as input parameters
    // return options and arguements
    // Option option;
    // vector<string> args;
    // Option::Parse(option, args, argc, argv);
    OptionMgr::Instance().PrintUsage();
    OptionMgr::Instance().Parse(args, argc, argv);
    for(int i = 0;i<args.size();++i)
        std::cout<<"Arg1: "<<args[i]<<std::endl;
    OptionMgr::Instance().PrintValue();
    OptionRef dir = OptionMgr::Instance()["dir"];
    OptionRef d = OptionMgr::Instance()["d"];
    OptionRef None = OptionMgr::Instance()["None"];
    if ( dir != NO_SUCH_OPTION)
        std::cout<<"Dir: "<<dir.GetRef().GetString()<<std::endl;
    if ( d != NO_SUCH_OPTION)
        std::cout<<"Dir: "<<dir.GetRef().GetString()<<std::endl;

    if ( None == NO_SUCH_OPTION)
        std::cout<<"No such option : None"<<std::endl;
    return 0;
}
