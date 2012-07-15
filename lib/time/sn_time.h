#ifndef _SN_TIME_H
#define _SN_TIME_H

#include "snack_types.h"
#include "snack_macro.h"

#include "sn_time_macro.h"

namespace snack
{
    class SNTime
    {
        public:
            SNTime();
            SNTime(const SNTime& t);
            SNTime(const tm*);

            static SNTime Now();

            String GetString(const String& fmt);
            String GetString();

            Bool operator==(const SNTime&);
            Bool operator!=(const SNTime&);
            Bool operator>=(const SNTime&);
            Bool operator<=(const SNTime&);
            Bool operator>(const SNTime&);
            Bool operator<(const SNTime&);
            SNTime& operator=(const SNTime&);

            // For debug only
            void Print();

            // Get Methods
            Int GetDate(){return mday_;}
            Int GetMonth(){return mon_;}
            Int GetYear(){return year_;}
            Int GetHour(){return hour_;}
            Int GetMin(){return min_;}
            Int GetSec(){return sec_;}
            Int GetMS(){return ms_;}
            Int GetUS(){return us_;}
            Int GetWeekDay(){}

            // Set Methods
            void SetTimeZone(Int zone){time_zone_ = zone;}


        private:
            Int time_zone_;
            Int year_;
            Int mon_;
            Int mday_;
            Int wday_;
            Int yday_;
            Int hour_;
            Int min_;
            Int sec_;
            Int isdst_;
            Int ms_;
            Int us_; 
    };
}

#endif // _SN_TIME_H
