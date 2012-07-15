#include <stdio.h>
#include <time.h>

#include <iostream>
#include <sstream>
using namespace std;
#include "sn_time.h"

namespace snack
{
    SNTime::SNTime()
    {

    }

    SNTime::SNTime(const tm* t)
    {
      time_zone_ = UTC;
      sec_ = t->tm_sec;
      min_ = t->tm_min;
      hour_ = t->tm_hour;
      mday_ = t->tm_mday;
      mon_ = t->tm_mon+1;
      year_ = t->tm_year+1900;
      wday_ = t->tm_wday;
      yday_ = t->tm_yday;
      isdst_ = t->tm_isdst;
    }

    SNTime::SNTime(const SNTime& t)
    {
    }

    SNTime SNTime::Now()
    {
      time_t rawtime;
      struct tm* ptm;
      time(&rawtime);
      ptm = gmtime(&rawtime);
      return SNTime(ptm);
    }

    void SNTime::Print()
    { 
        printf("Year:%d Month:%d Date:%d Hour:%d Minute:%d Second:%d\n", year_+1900, mon_+1, mday_, (hour_+time_zone_)%24, min_, sec_); 
        return;
    }

    // There are some many formats can be used. e.g.
    // Year: 2012, 12 -- $YY $Y2
    // Month: JAN, January, 1; -- $MA, $MS, $MD
    // Day: 1st, 2nd, 3rd, 4th, 5th, 6th, 7th, 8th, 9th, 10th, 11th, 12th, 13th, 14th, 15th, 16th, 17th, 18th, 19th, 20th, 21st, 22nd, 23rd, 24th, 25th, 26th, 27th, 28th, 29th, 30th, 31st -- $DS, $DD
    // Week: Monday, Thuesday, Wednesday, Thursday, Friday, Saturday, Sunday -- $WW, $WD
    // Hour: 12 or 24 -- $H1, $H2
    // Minute: 0~59 -- $MI
    // Second: 0~61 -- $SS
    String SNTime::GetString(const String& fmt)
    { 
        //String str;
        stringstream str;
        Int idx = 0;
        for(  ; idx < fmt.size(); ++idx)
        {
            if (fmt[idx] == '$' and fmt[idx+1] != '$')
            {
                ++idx;
                switch(fmt[idx++])
                {
                    case 'Y': 
                        switch(fmt[idx])
                        {
                            case 'Y': 
                                str<<year_;
                                break;
                            case '2':
                                str<<year_%100;
                                break;
                            default:
                                printf("Sorry, $Y%c is not supported\n",fmt[idx]);
                                str<<"$Y"<<fmt[idx];
                                break;
                        }
                        break;
                    case 'M': // Month or Minute
                        switch(fmt[idx])
                        {
                            case 'A': 
                                switch(mon_)
                                {
                                    case 1:
                                        str<<"JAN";
                                        break;
                                    case 2:
                                        str<<"FEB";
                                        break;
                                    case 3:
                                        str<<"MAR";
                                        break;
                                    case 4:
                                        str<<"APR";
                                        break;
                                    case 5:
                                        str<<"MAY";
                                        break;
                                    case 6:
                                        str<<"JUN";
                                        break;
                                    case 7:
                                        str<<"JUL";
                                        break;
                                    case 8:
                                        str<<"AUG";
                                        break;
                                    case 9:
                                        str<<"SEP";
                                        break;
                                    case 10:
                                        str<<"OCT";
                                        break;
                                    case 11:
                                        str<<"NOV";
                                        break;
                                    case 12:
                                        str<<"DEC";
                                        break;
                                }
                                break;
                            case 'S':
                                switch(mon_)
                                {
                                    case 1:
                                        str<<"January";
                                        break;
                                    case 2:
                                        str<<"February";
                                        break;
                                    case 3:
                                        str<<"March";
                                        break;
                                    case 4:
                                        str<<"April";
                                        break;
                                    case 5:
                                        str<<"May";
                                        break;
                                    case 6:
                                        str<<"June";
                                        break;
                                    case 7:
                                        str<<"July";
                                        break;
                                    case 8:
                                        str<<"August";
                                        break;
                                    case 9:
                                        str<<"September";
                                        break;
                                    case 10:
                                        str<<"October";
                                        break;
                                    case 11:
                                        str<<"November";
                                        break;
                                    case 12:
                                        str<<"December";
                                        break;
                                }
                                break;
                            case 'D':
                                str<<mon_;
                                break;
                            case 'I':
                                str<<min_;
                                break;
                            default:
                                printf("Sorry, $M%c is not supported\n",fmt[idx]);
                                str<<"$M"<<fmt[idx];
                                break;
                        }
                        break;
                    case 'D': 
                        switch(fmt[idx])
                        {
                            case 'S': 
                                str<<mday_;
                                switch(mday_)
                                {
                                    case 1:
                                    case 31:
                                        str<<"st";
                                        break;
                                    case 2:
                                        str<<"nd";
                                    case 3:
                                        str<<"rd";
                                    default:
                                        str<<"th";
                                        break;
                                }
                                break;
                            case 'D':
                                str<<mday_;
                                break;
                        }
                        break;
                    case 'H':
                        idx++;
                        switch(idx)
                        {
                            case '1':
                                str<<(hour_+time_zone_)%12;
                                break;
                            case '2':
                                str<<(hour_+time_zone_)%24;
                                break;
                            default:
                                printf("Sorry, $H%c is not supported\n",fmt[idx]);
                                str<<"$H"<<fmt[idx];
                        }
                        break;
                    case 'W':
                        printf(" Week");
                        break;
                    default:
                        printf("Sorry, $%c is not supported\n",fmt[idx]);
                        str<<'$'<<fmt[idx];
                        break;
                }
            } else { 
                str<<fmt[idx];
            }
        }
        return str.str();
    }

    String SNTime::GetString()
    {

    }

    Bool SNTime::operator==(const SNTime&)
    {

    }

    Bool SNTime::operator!=(const SNTime&)
    {

    }

    Bool SNTime::operator>=(const SNTime&)
    {

    }

    Bool SNTime::operator<=(const SNTime&)
    {

    }

    Bool SNTime::operator>(const SNTime&)
    {

    }

    Bool SNTime::operator<(const SNTime&)
    {

    }

    SNTime& SNTime::operator=(const SNTime&)
    {

    }
}
