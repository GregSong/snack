#include <time.h>
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
      mon_ = t->tm_mon;
      year_ = t->tm_year;
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

    String SNTime::GetString(const String& fmt)
    {
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
