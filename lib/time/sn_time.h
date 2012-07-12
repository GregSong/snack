#ifndef _SN_TIME_H
#define _SN_TIME_H

namespace snack
{
    class SNTime
    {
        public:
            SNTime();
            SNTime(const SNTime& t);

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

            Int GetDate(){return date_;}
            Int GetMonth(){return month_;}
            Int GetYear(){return year_;}
            Int GetHour(){return hour_;}
            Int GetMinute(){return minute_;}
            Int GetSecond(){return second_;}
            Int GetMS(){return ms_;}
            Int GetUS(){return us_;}
            Int GetWeek(){}


        private:
            Int time_zone_;
            Int year_;
            Int month_;
            Int date_;
            Int hour_;
            Int minute_;
            Int second_;
            Int ms_;
            Int us_; 
    }
}

#endif // _SN_TIME_H
