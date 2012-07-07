#ifndef _SNACK_OPTION_IMPL_H
#define _SNACK_OPTION_IMPL_H

#include <map>

#include "snack_types.h"
#include "snack_debug.h"

#include "singleton.h"

namespace snack
{
    class Option;
    typedef std::map<String, int> OptionsMap;
    typedef std::map<Char, int> OptionsAbbrMap;

    typedef std::vector<Option> Options;

    class OptionMgr:public Singleton<OptionMgr>
    {
        public:
            static void Register(Option& opt);
            int Parse(Strings&, int, char**);
            void Add(Option opt);
            void PrintUsage();
            int  PrintValue();
        private:
            Options opts_;
            OptionsMap opt_map_;
            OptionsAbbrMap opt_abb_map_;
    };

    class Option
    {
        public:
            friend class OptionMgr;
            typedef enum{
                BOOL,
                STRING, 
                ARRAY, 
                INT,
                DOUBLE
            } OPTIONTYPE;
            // Constructor
            Option(const String& name, 
                   const Char   abbr,
                   const OPTIONTYPE type,
                   const String& default_v="",
                   const String& desc="");
            Option(const Option& opt);

            // Get methods
            OPTIONTYPE get_opt_type(){return type_;}
            String& get_opt_name(){return opt_name_;}
            Char    get_abbreviation(){return opt_abbreviation_;}
            String& get_str_value(){return opt_str_value_;}
            String& get_desc(){return opt_desc_;}
            Bool    IsSet(){return opt_value_.bool_value_;}

            // Set methods
            void    set_opt_name(const String& str){opt_name_ = str;}
            void    set_opt_abbreviation(const Char ab){opt_abbreviation_ = ab;} 
            void    set_opt_str_value(const String& v){opt_str_value_ = v;}
            void    set_opt_set(Bool s){opt_value_.bool_value_ = s;}
            int     Set_value(const String& str);
        private:
            Option(){}

            String opt_name_;
            Char   opt_abbreviation_;
            String opt_str_value_; 
            String opt_desc_;
            OPTIONTYPE type_;
            Strings opt_values_;
            union{
                Int int_value_;
                Char char_value_;
                Double double_value_;
                Bool   bool_value_;
            } opt_value_;
    };
}
#endif // _SNACK_OPTION_IMPL_H
