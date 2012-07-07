#include <iostream>
#include <sstream>
using namespace std;

#include "option_error.h"
#include "option_impl.h"

namespace snack
{

    Option::Option(const String& name, 
                   const Char   abbr,
                   const OPTIONTYPE type,
                   const String& default_v,
                   const String& desc):
        type_(type),
        opt_name_(name),
        opt_abbreviation_(abbr),
        opt_desc_(desc)
    {
        if (!default_v.empty())
        {
            stringstream ss(default_v);
            switch(type)
            {
                case BOOL: 
                    ss>>opt_value_.bool_value_;
                    break;
                case STRING:
                    ss>>opt_str_value_;
                    break;
                case ARRAY:
                    opt_values_.push_back(default_v);
                    break;
                case INT:
                    ss>>opt_value_.int_value_;
                    break;
                case DOUBLE:
                    ss>>opt_value_.double_value_;
                    break;
                default:
                    break;
            }
        }
        OptionMgr::Register(*this);
    }

    Option::Option(const Option& opt):
        opt_name_(opt.opt_name_),
        opt_abbreviation_(opt.opt_abbreviation_),
        opt_str_value_(opt.opt_str_value_),
        opt_desc_(opt.opt_desc_),
        type_(opt.type_),
        opt_value_(opt.opt_value_),
        opt_values_(opt.opt_values_.begin(), opt.opt_values_.end())
    { 
    }

    int Option::Set_value(const String& str)
    {
            stringstream ss(str);
            switch(type_)
            {
                case BOOL: 
                    ss>>opt_value_.bool_value_;
                    break;
                case STRING:
                    ss>>opt_str_value_;
                    break;
                case ARRAY:
                    opt_values_.push_back(str);
                    break;
                case INT:
                    ss>>opt_value_.int_value_;
                    break;
                case DOUBLE:
                    ss>>opt_value_.double_value_;
                    break;
                default:
                    break;
            }
    }

    void OptionMgr::Add(Option opt)
    {
        opts_.push_back(opt);
        if (!opt.get_opt_name().empty())
            opt_map_.insert(pair<String, int>(opt.get_opt_name(), opts_.size()-1));
        if (opt.get_abbreviation() != '\0')
            opt_abb_map_.insert(pair<Char, int>(opt.get_abbreviation(), opts_.size()-1));
    }

    int OptionMgr::Parse(Strings& args, int argc, char** argv)
    {
        DEBUG_PRINT_FUNC();
        int p = 0;
        while (++p<argc)
        {
            char* idx = argv[p];
            String name;
            String value;
            if (*idx == '-' && *(idx + 1) == '-')
            {
                // Long option name
                if (*(idx+2) == ' ')
                {
                    //report error
                    return OPTION_NO_NAME;
                }else{
                    idx += 2;
                    while(*idx != '\0')
                        name.push_back(*(idx++));
                    // validate with option
                    OptionsMap::iterator iter = opt_map_.find(name);
                    if ( iter == opt_map_.end())
                    {
                        return OPTION_NOT_FOUND;
                    }

                    if ( opts_[iter->second].get_opt_type() == Option::BOOL)
                    {
                        opts_[iter->second].Set_value("1");
                        continue;
                    }

                    char* idx = argv[++p];
                    if(*idx != '-')
                    {
                        while(*idx != '\0')
                            value.push_back(*(idx++)); 
                    }
                    opts_[iter->second].Set_value(value);
                }
            } else if (*idx == '-') { 
                // short option name
                if (*(idx+1) == ' ')
                {
                    //report error
                    return OPTION_NO_NAME;
                }else{
                    idx += 1;
                    while(*idx != '\0')
                        name.push_back(*(idx++));
                    // validate with option
                    OptionsAbbrMap::iterator iter = opt_abb_map_.find(name[0]);
                    if ( iter == opt_abb_map_.end())
                    {
                        return OPTION_NOT_FOUND;
                    }

                    if ( opts_[iter->second].get_opt_type() == Option::BOOL)
                    {
                        opts_[iter->second].Set_value("1");
                        continue;
                    }

                    if (p >= argc-1)
                    {
                        return OPTION_NO_VALUE;
                    }

                    char* idx = argv[++p];
                    if(*idx != '-')
                    {
                        while(*idx != '\0')
                            value.push_back(*(idx++)); 
                    }
                    opts_[iter->second].Set_value(value);
                }
            }else{
                args.push_back(argv[p]);
                continue;
            }
            // log(severity, file_name, line, function, fmt,argv);
            std::cout<<"name: "<<name<<"\t"<<"value: "<<value<<std::endl;
        }
    }
    void OptionMgr::Register(Option& opt)
    {
        Instance().Add(opt);
    }

    void OptionMgr::PrintUsage()
    { 
        Options::iterator iter;
        cout<<"\033[31mUsage:"<<endl;
        for(iter=opts_.begin();iter!=opts_.end();++iter)
        {
            cout<<iter->get_opt_name()<<"\t"<<iter->get_abbreviation()<<"\t"<<iter->get_desc()<<endl;
        }
        cout<<"\033[m"<<endl;
    }
    
    int OptionMgr::PrintValue()
    {
        cout<<"\033[32mOpiton values are:"<<endl;
        Options::iterator iter;
        for(iter=opts_.begin();iter!=opts_.end();++iter)
        {
            cout<<iter->get_opt_name()<<"\t"<<iter->get_abbreviation()<<"\t";
            int i = 0;
            switch(iter->get_opt_type())
            {
                case Option::BOOL: 
                    cout<<(iter->opt_value_.bool_value_?"TRUE":"FALSE")<<endl;
                    break;
                case Option::STRING:
                    cout<<iter->opt_str_value_<<endl;
                    break;
                case Option::ARRAY:
                    if (iter->opt_values_.size() != 0)
                    {
                        for(;i<iter->opt_values_.size()-1;++i)
                        {
                            cout<<iter->opt_values_[i]<<"|";
                        }
                        cout<<iter->opt_values_[i];
                    }
                    cout<<endl;
                    break;
                case Option::INT:
                    cout<<iter->opt_value_.int_value_<<endl;
                    break;
                case Option::DOUBLE:
                    cout<<iter->opt_value_.double_value_<<endl;;
                    break;
            }
        }
        cout<<"\033[m"<<endl;
    }
}
