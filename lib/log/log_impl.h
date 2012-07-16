// ---------------------------------------------------------------------------
// File name: log_impl.h
// Description: header file of log module    
// Author: Greg Song (email kuroro2121@gmail.com, MSN kingcri8837@sina.com)
// Todo:
//      1. a general stream to write log;
//      2. dynamic control of log level. Maybe a named pipe;
// ---------------------------------------------------------------------------

#ifndef _LOG_IMPL_H_
#define _LOG_IMPL_H_

#include "snack_types.h"
#include "snack_debug.h"

#include "singleton.h"

namespace snack
{
    class Logger;
    class LoggerMgr:public Singleton<LoggerMgr>
    {
        public:
            static void Register(Logger& logger);
    };

    class Logger
    {
        public:
            explicit Logger(const Char* mod_name, Int log_level);
            explicit Logger(const String mod_name, Int log_level);

            // Main inferface of log module
            Int Log(Int severity, Int fmt_code, ...);
        private:
            // A stream use to write log

    };
}

#endif // _LOG_IMPL_H
