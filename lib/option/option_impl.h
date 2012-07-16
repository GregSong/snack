#ifndef _SNACK_OPTION_IMPL_H
#define _SNACK_OPTION_IMPL_H

#include <map>

#include "snack_types.h"
#include "snack_debug.h"

#include "singleton.h"

namespace snack
{
    class Option;
    class OptionRef;
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
            OptionRef operator[](const String& opt);
        private:
            Options opts_;
            OptionsMap opt_map_;
            OptionsAbbrMap opt_abb_map_;
    };

    class Option
    {
        public:
            friend class OptionRef;
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

            // Get methods
            Int     GetInt(){return opt_value_.int_value_;}
            Char    GetChar(){return opt_value_.char_value_;}
            Double  GetDouble(){return opt_value_.double_value_;}
            Bool    GetBool(){return opt_value_.bool_value_;}
            String& GetString(){return opt_str_value_;}
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

#define NO_SUCH_OPTION OptionRef::invalid_opt
    class OptionRef
    {
        public:
            OptionRef(Option &opt):ref_(opt){};
            OptionRef(const OptionRef& ref):ref_(ref.ref_){};
            Bool operator==(const OptionRef& opt_ref){ return &ref_ == &opt_ref.ref_;}
            Bool operator!=(const OptionRef& opt_ref){ return !(&ref_ == &opt_ref.ref_);}
            Option* operator->(){return &ref_;}
            // Actually I don't like this idea to use GetRef. It is ugly
            Option& GetRef(){return ref_;}

            // This is a temperary solution for 'not such option'. This causes extra space expense
            // I think to solve this problem I can move most of data member of Option into OptionImpl
            // and add invalid status to Option and space saved
            static Option invalid_opt;
        private:
            OptionRef& operator=(const OptionRef & ){}
            Option& ref_;
    };
    Option OptionRef::invalid_opt;
}
#endif // _SNACK_OPTION_IMPL_H
