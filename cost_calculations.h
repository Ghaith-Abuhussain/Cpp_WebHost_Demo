/////// cost calculation parameters
const char * weekday[] = { "Sun  ", "Mon  ", "Tue  ", "Wed  ", "Thu  ", "Fri  ", "Sat  "};
int fin_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date_type
{
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
};


date_type get_date_from_string(std::string date)
{
    date_type date_time;
    char first_date[50] = "";
    char second_date[50] = "";
    int index = 1;
    for(int i = 0; i < date.length(); i++)
    {
        if(index == 1)
        {
            if(date[i] == ' ')
            {
                index++;
            }
            else
            {
                first_date[i] = date[i];
            }
        }
        else if(index == 2)
        {
            second_date[i - strlen(first_date) - 1] = date[i];
        }
    }
    sscanf(first_date, "%d-%d-%d", &date_time.year, &date_time.month, &date_time.day);
    sscanf(second_date, "%d:%d:%d", &date_time.hour, &date_time.minute, &date_time.second);
    return date_time;
}

struct hour_in_day
{
    int hour;
    int minute;
    int second;
};

struct time_date_daily
{
    int year;
    int month;
    int month_day;
    int weekday;
    const char * week_day;
    std::vector<hour_in_day> all_hour_in_day;
    int day_period;
};

struct parking_period
{
    time_t entryTime = 0;
    time_t payappTime = 0;
    std::vector<time_date_daily> parking_days;
    int total_period = 0;
};

std::vector<Block>                  block_list;

void print_date_type(date_type time_now)
{
    std::cout << time_now.year << "-" << time_now.month << "-" << time_now.day 
    << " " << time_now.hour << ":" << time_now.minute << ":" << time_now.second << "\n";
}

time_t _mktime_slow(struct tm *tm)
{
    static struct tm cache = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    static time_t time_cache = 0;
    static time_t (*mktime_real)(struct tm *tm) = NULL;
    time_t result;
    time_t hmsarg;

    /* Load real mktime once into a static */
    if (!mktime_real)
    {
        void *handle;

        /* To forgive this cast, please see man dlopen(3). */
        dlerror();
        handle = dlsym(RTLD_NEXT, "mktime");
        *(void **) (&mktime_real) = handle;

        if (!mktime_real)
        {
            fprintf(stderr, "loading mktime: %s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    }

    /* the epoch time portion of the request */
    hmsarg = 3600 * tm->tm_hour
            +  60 * tm->tm_min
            +       tm->tm_sec;

    if ( cache.tm_mday    == tm->tm_mday
         && cache.tm_mon  == tm->tm_mon
         && cache.tm_year == tm->tm_year )
    {
        /* cached - just add h,m,s from request to midnight */
        result = time_cache + hmsarg;

        /* Obscure, but documented, return value: only this value in arg struct.         
         * 
         * BUG: dst switchover was computed by mktime_real() for time 00:00:00
         * of arg day. So this return value WILL be wrong for switchover days
         * after the switchover occurs.  There is no clean way to detect this
         * situation in stock glibc.  This bug will be reflected in unit test
         * until fixed.  See also github issues #1 and #2.
         */
        tm->tm_isdst  = cache.tm_isdst;
    }
    else
    {
        /* not cached - recompute midnight on requested day */
        cache.tm_mday = tm->tm_mday;
        cache.tm_mon  = tm->tm_mon;
        cache.tm_year = tm->tm_year;
        time_cache    = mktime_real(&cache);
        tm->tm_isdst  = cache.tm_isdst;

        result = (-1 == time_cache) ? -1 : time_cache + hmsarg;
    }

    return result;
}

std::string calcCurrentTime(time_t now)
{
    if(now == 0) return "000000000000";
    tm *my_time = localtime(&now);
    std::string date = "now = ";
    date += std::to_string(my_time->tm_year + 1900);
    date += "-";
    date += std::to_string(my_time->tm_mon + 1);
    date += "-";
    date += std::to_string(my_time->tm_mday);
    date += " ";
    date += std::to_string(my_time->tm_hour);
    date += ":";
    date += std::to_string(my_time->tm_min);
    date += ":";
    date += std::to_string(my_time->tm_sec);
    date += " ";
    if (my_time->tm_hour > 12)
            date += "PM";
    else
            date += "AM";



    std::stringstream hex_date;
    hex_date << std::setfill('0') << std::setw(2) << std::hex << (my_time->tm_year - 100)
             << std::setfill('0') << std::setw(2) << std::hex << (my_time->tm_mon + 1)
             << std::setfill('0') << std::setw(2) << std::hex << my_time->tm_mday
             << std::setfill('0') << std::setw(2) << std::hex << (my_time->tm_hour)
             << std::setfill('0') << std::setw(2) << std::hex << my_time->tm_min
             << std::setfill('0') << std::setw(2) << std::hex << my_time->tm_sec;

    std::string v_temp_string = hex_date.str();
    std::string v_ = "123456789ABC";;
    for (int i = 0; v_temp_string[i] != '\0'; i++)
    {
            v_[i] = toupper(v_temp_string[i]);
    }
    return v_;
}

time_t char_to_time_t(unsigned char data1, unsigned char data2, unsigned char data3, unsigned char data4, unsigned char data5, unsigned char data6)
{
    tm time_and_date;
    time_and_date.tm_year = data1 + 100;
    time_and_date.tm_mon = data2 - 1;
    time_and_date.tm_mday = data3;
    time_and_date.tm_hour = data4;
    time_and_date.tm_min = data5;
    time_and_date.tm_sec = data6;
    time_t datetime = _mktime_slow(&time_and_date);
    return datetime;
}

block_type get_block_type(int type)
{
    if(type == 0)
    {
        return Normal;
    }
    if(type == 1)
    {
        return Sub_amount_start;
    }
    if(type == 2)
    {
        return Sub_amount_end;
    }
    return Normal;
}
    
Relation get_block_Relation(int relation)
{
    if(relation == 0)
    {
        return Great;
    }
    if(relation == 1)
    {
        return GreatOrEqual;
    }
    if(relation == 2)
    {
        return Less;
    }
    if(relation == 3)
    {
        return LessOrEqual;
    }
    return Great;
}

bool compare(int v1, int v2, Relation rel)
{
    if(rel == Great)
        return (v1 > v2);

    if (rel == GreatOrEqual)
        return (v1 >= v2);

    if (rel == Less)
        return (v1 < v2);

    if (rel == LessOrEqual)
        return (v1 <= v2);

    return false;
}

std::string print_block_type(block_type type)
{
    if(type == Normal)
        return "Normal";

    if (type == Sub_amount_start)
        //return "Sub_amount_start";
        return "SubStr";

    if (type == Sub_amount_end)
        //return "Sub_amount_end";
        return "SubEnd";
    return "";
}

std::string print_Relation(Relation rel)
{
    if(rel == Great)
        //return "Great";
        return ">";

    if (rel == GreatOrEqual)
        //return "GreatOrEqual";
        return ">=";

    if (rel == Less)
        //return "Less";
        return "<";

    if (rel == LessOrEqual)
        //return "LessOrEqual";
        return "<=";
    return "";
}

void extract_day_hours(std::vector<hour_in_day> &all_hours_in_day, time_t entryTime, time_t payappTime, std::string type)
{
    all_hours_in_day.clear();
    bool same_day = false;
    bool same_hour = false;
    tm *a = localtime(&entryTime);
    tm _entryTime;
    _entryTime.tm_year = a->tm_year;
    _entryTime.tm_mon = a->tm_mon;
    _entryTime.tm_mday = a->tm_mday;
    _entryTime.tm_wday = a->tm_wday;
    _entryTime.tm_hour = a->tm_hour;
    _entryTime.tm_min = a->tm_min;
    _entryTime.tm_sec = a->tm_sec;
    
    tm *b = localtime(&payappTime);
    tm _payappTime;
    _payappTime.tm_year = b->tm_year;
    _payappTime.tm_mon = b->tm_mon;
    _payappTime.tm_mday = b->tm_mday;
    _payappTime.tm_wday = b->tm_wday;
    _payappTime.tm_hour = b->tm_hour;
    _payappTime.tm_min = b->tm_min;
    _payappTime.tm_sec = b->tm_sec;
    
    if((_payappTime.tm_year == _entryTime.tm_year) && 
       (_payappTime.tm_mon == _entryTime.tm_mon) && 
       (_payappTime.tm_mday == _entryTime.tm_mday))
    {
        same_day = true;
    }
    if(_payappTime.tm_hour == _entryTime.tm_hour)
    {
        same_hour = true;
    }
    if(type == "enter")
    {
        if(same_day)
        {
            if(same_hour)
            {
                hour_in_day current_hour;
                current_hour.hour = _entryTime.tm_hour;
                if(_payappTime.tm_sec >=  _entryTime.tm_sec)
                {
                    current_hour.minute = _payappTime.tm_min - _entryTime.tm_min;
                    current_hour.second = _payappTime.tm_sec - _entryTime.tm_sec;
                }
                else
                {
                    current_hour.minute = _payappTime.tm_min - _entryTime.tm_min - 1;
                    current_hour.second = 60 + _payappTime.tm_sec - _entryTime.tm_sec;
                }
                all_hours_in_day.push_back(current_hour);
            }
            else
            {
                for(int i = _entryTime.tm_hour; i <= _payappTime.tm_hour; i++)
                {
                    
                    hour_in_day current_hour;
                    if(i == _entryTime.tm_hour)
                    {
                        
                        current_hour.hour = i;
                        if(_entryTime.tm_sec == 0)
                        {
                            current_hour.minute = 60 - _entryTime.tm_min;
                            current_hour.second = 0;
                        }
                        else
                        {
                            current_hour.minute = 60 - _entryTime.tm_min - 1;
                            current_hour.second = 60 - _entryTime.tm_sec;
                        }
                    }
                    else if(i == _payappTime.tm_hour)
                    {
                        current_hour.hour = i;
                        current_hour.minute = _payappTime.tm_min;
                        current_hour.second = _payappTime.tm_sec;
                    }
                    else
                    {
                        current_hour.hour = i;
                        current_hour.minute = 60;
                        current_hour.second = 0;
                    }
                    //std::cout << current_hour.hour << ":" << current_hour.minute << ":" << current_hour.second << "\n";
                    all_hours_in_day.push_back(current_hour);
                }
            }
        }
        else
        {
            for(int i = _entryTime.tm_hour; i < 24; i++)
            {
                hour_in_day current_hour;
                if(i == _entryTime.tm_hour)
                {
                    current_hour.hour = i;
                    if(_entryTime.tm_sec == 0)
                    {
                        current_hour.minute = 60 - _entryTime.tm_min;
                        current_hour.second = 0;
                    }
                    else
                    {
                        current_hour.minute = 60 - _entryTime.tm_min - 1;
                        current_hour.second = 60 - _entryTime.tm_sec;
                    }
                }
                else
                {
                    current_hour.hour = i;
                    current_hour.minute = 60;
                    current_hour.second = 0;
                }
                all_hours_in_day.push_back(current_hour);
            }
        }
    }
    if(type == "exit")
    {
        if(!same_day)
        {
            for(int i = 0; i < _payappTime.tm_hour + 1; i++)
            {
                hour_in_day current_hour;
                if(i == _payappTime.tm_hour)
                {
                    current_hour.hour = i;
                    current_hour.minute = _payappTime.tm_min;
                    current_hour.second = _payappTime.tm_sec;
                }
                else
                {
                    current_hour.hour = i;
                    current_hour.minute = 60;
                    current_hour.second = 0;
                }
                all_hours_in_day.push_back(current_hour);
            }
        }
    }
}

std::vector<hour_in_day> extract_all_day_hours()
{
    std::vector<hour_in_day> all_hour_day;
    for(int i = 0; i < 24; i++)
    {
        hour_in_day hour_day;
        hour_day.hour = i;
        hour_day.minute = 60;
        hour_day.second = 0;
        all_hour_day.push_back(hour_day);
    }
    return all_hour_day;
}

void calculate_every_day_period(parking_period &_parking_period)
{
    int day_period = 0;
    int total_period = 0;
    for(int i = 0; i < _parking_period.parking_days.size(); i++)
    {
        day_period = 0;
        for(int j = 0; j < _parking_period.parking_days[i].all_hour_in_day.size(); j++)
        {
            day_period += ((_parking_period.parking_days[i].all_hour_in_day[j].minute * 60) + (_parking_period.parking_days[i].all_hour_in_day[j].second));
        }
        _parking_period.parking_days[i].day_period = day_period;
        total_period += day_period;
    }
    _parking_period.total_period = total_period;
}

std::vector<time_date_daily> turn_tow_date_into_vector_days(time_t payappTime, time_t entryTime)
{
    std::vector<time_date_daily> _parking_period;
    if(payappTime <= entryTime)
        return _parking_period;
    else
    {
        tm *a = localtime(&entryTime);
        tm _entryTime;
        _entryTime.tm_year = a->tm_year;
        _entryTime.tm_mon = a->tm_mon;
        _entryTime.tm_mday = a->tm_mday;
        _entryTime.tm_wday = a->tm_wday;
        _entryTime.tm_hour = a->tm_hour;
        _entryTime.tm_min = a->tm_min;
        _entryTime.tm_sec = a->tm_sec;
        tm *b = localtime(&payappTime);
        tm _payappTime;
        _payappTime.tm_year = b->tm_year;
        _payappTime.tm_mon = b->tm_mon;
        _payappTime.tm_mday = b->tm_mday;
        _payappTime.tm_wday = b->tm_wday;
        _payappTime.tm_hour = b->tm_hour;
        _payappTime.tm_min = b->tm_min;
        _payappTime.tm_sec = b->tm_sec;
        
        bool b_break = false;
        for(; _entryTime.tm_year <= _payappTime.tm_year; _entryTime.tm_year++)
        {
            mktime(&_entryTime);
            if((((_entryTime.tm_year + 1900) % 4 == 0) && ((_entryTime.tm_year + 1900) % 100 != 0)) || ((_entryTime.tm_year + 1900) % 400 == 0))
            {
                fin_of_month[1] = 29;
            }
            else
            {
                fin_of_month[1] = 28;
            }
            for(;  _entryTime.tm_mon < 12;  _entryTime.tm_mon++)
            {
                if ( _entryTime.tm_mon > _payappTime.tm_mon && _entryTime.tm_year == _payappTime.tm_year) 
                {
                    break;
                }
                if (b_break) 
                {
                    break;
                }
                for(; _entryTime.tm_mday <= fin_of_month[_entryTime.tm_mon]; _entryTime.tm_mday++)
                {
                    if (_entryTime.tm_mday > _payappTime.tm_mday && _entryTime.tm_mon == _payappTime.tm_mon && _entryTime.tm_year == _payappTime.tm_year) 
                    {
                        b_break = true;
                        break;
                    }
                    mktime(&_entryTime);
                    time_date_daily current_day;
                    current_day.year = _entryTime.tm_year;
                    current_day.month = _entryTime.tm_mon;
                    current_day.month_day = _entryTime.tm_mday;
                    current_day.weekday = _entryTime.tm_wday;
                    current_day.week_day = weekday[_entryTime.tm_wday];
                    if(_parking_period.size() == 0)
                    {
                        extract_day_hours(current_day.all_hour_in_day, entryTime, payappTime, "enter");
                    }
                    else
                    {
                        current_day.all_hour_in_day = extract_all_day_hours();
                    }
                    _parking_period.push_back(current_day);
                }
                if(!b_break)
                {
                    _entryTime.tm_mday = 1;
                    mktime(&_entryTime);
                }
            }
            if(!b_break)
            {
                _entryTime.tm_mon = 0;
                mktime(&_entryTime);
            }
        }
    }
    if(_parking_period.size() > 1)
    {
        extract_day_hours(_parking_period[_parking_period.size() - 1].all_hour_in_day, entryTime, payappTime, "exit");
    }
    return _parking_period;
}

void delete_period(parking_period &_parking_period ,int period_in_second)
{ 
    if(_parking_period.total_period > period_in_second)
    {
        _parking_period.total_period -= (period_in_second);
        int new_parking_period_length = 0;
        int hour_period = period_in_second / 3600;
        int minute_period = (period_in_second % 3600) / 60;
        int second_period = (period_in_second % 3600) % 60;
        if(period_in_second < _parking_period.parking_days[0].day_period)
        {
            _parking_period.parking_days[0].day_period -= period_in_second;
            new_parking_period_length = _parking_period.parking_days.size() - (period_in_second / 86400);
            hour_in_day new_entry_hour;
            if(second_period > _parking_period.parking_days[0].all_hour_in_day[0].second)
            {
                _parking_period.parking_days[0].all_hour_in_day[0].second += 60;
                _parking_period.parking_days[0].all_hour_in_day[0].minute--;
                new_entry_hour.second = _parking_period.parking_days[0].all_hour_in_day[0].second - second_period;
            }
            else
            {
                new_entry_hour.second = _parking_period.parking_days[0].all_hour_in_day[0].second - second_period;
            }
            if(minute_period > _parking_period.parking_days[0].all_hour_in_day[0].minute)
            {
                _parking_period.parking_days[0].all_hour_in_day[0].minute += 60;
                hour_period++;
                new_entry_hour.minute = _parking_period.parking_days[0].all_hour_in_day[0].minute - minute_period;
            }
            else
            {
                new_entry_hour.minute = _parking_period.parking_days[0].all_hour_in_day[0].minute - minute_period;
            }
            _parking_period.parking_days[0].all_hour_in_day.erase
            (
                _parking_period.parking_days[0].all_hour_in_day.begin(), 
                _parking_period.parking_days[0].all_hour_in_day.begin() + hour_period
            );
            _parking_period.parking_days[0].all_hour_in_day[0].minute = new_entry_hour.minute;
            _parking_period.parking_days[0].all_hour_in_day[0].second = new_entry_hour.second;
        }
        else
        {
            do
            {
                period_in_second -= _parking_period.parking_days[0].day_period;
                _parking_period.parking_days.erase(_parking_period.parking_days.begin(), _parking_period.parking_days.begin() + 1);
            }
            while(period_in_second >= _parking_period.parking_days[0].day_period);
            if(period_in_second > 0 && period_in_second < _parking_period.parking_days[0].day_period)
            {
                _parking_period.parking_days[0].day_period -= period_in_second;
                int new_parking_period_length = 0;
                int hour_period = period_in_second / 3600;
                int minute_period = (period_in_second % 3600) / 60;
                int second_period = (period_in_second % 3600) % 60;
                new_parking_period_length = _parking_period.parking_days.size() - (period_in_second / 86400);
                hour_in_day new_entry_hour;
                if(second_period > _parking_period.parking_days[0].all_hour_in_day[0].second)
                {
                    _parking_period.parking_days[0].all_hour_in_day[0].second += 60;
                    _parking_period.parking_days[0].all_hour_in_day[0].minute--;
                    new_entry_hour.second = _parking_period.parking_days[0].all_hour_in_day[0].second - second_period;
                }
                else
                {
                    new_entry_hour.second = _parking_period.parking_days[0].all_hour_in_day[0].second - second_period;
                }
                if(minute_period > _parking_period.parking_days[0].all_hour_in_day[0].minute)
                {
                    _parking_period.parking_days[0].all_hour_in_day[0].minute += 60;
                    hour_period++;
                    new_entry_hour.minute = _parking_period.parking_days[0].all_hour_in_day[0].minute - minute_period;
                }
                else
                {
                    new_entry_hour.minute = _parking_period.parking_days[0].all_hour_in_day[0].minute - minute_period;
                }
                _parking_period.parking_days[0].all_hour_in_day.erase
                (
                    _parking_period.parking_days[0].all_hour_in_day.begin(), 
                    _parking_period.parking_days[0].all_hour_in_day.begin() + hour_period
                );
                _parking_period.parking_days[0].all_hour_in_day[0].minute = new_entry_hour.minute;
                _parking_period.parking_days[0].all_hour_in_day[0].second = new_entry_hour.second;
            }
            
            new_parking_period_length = _parking_period.parking_days.size() - (period_in_second / 86400) - 1;
        }
        
        tm _entryTime;
        _entryTime.tm_year = _parking_period.parking_days[0].year;
        _entryTime.tm_mon = _parking_period.parking_days[0].month;
        _entryTime.tm_mday = _parking_period.parking_days[0].month_day;
        _entryTime.tm_hour = _parking_period.parking_days[0].all_hour_in_day[0].hour;
        _entryTime.tm_min = 60 - _parking_period.parking_days[0].all_hour_in_day[0].minute - 1;
        if(_parking_period.parking_days[0].all_hour_in_day[0].second == 0)
        {
            _entryTime.tm_min ++;
            _entryTime.tm_sec = 0;
        }
        else
        {
            _entryTime.tm_sec = 60 - _parking_period.parking_days[0].all_hour_in_day[0].second;
        }
        _parking_period.entryTime = _mktime_slow(&_entryTime);
    }
    else
    {
        _parking_period.parking_days.clear();
        _parking_period.total_period = 0;
    }
}

void print_day_hours(std::vector<hour_in_day> day_hours)
{
    for(int i = 0; i < day_hours.size(); i++)
    {
        std::cout << day_hours[i].hour << ":" << day_hours[i].minute << ":" << day_hours[i].second << "\n";
    }
}

void print_parking_days(std::vector<time_date_daily> parking_days)
{
    for(int i = 0; i < parking_days.size(); i++)
    {
        std::cout << parking_days[i].year + 1900 << "/" << parking_days[i].month + 1 << "/" << parking_days[i].month_day << " " << weekday[parking_days[i].weekday] << "\n";
    }
}

bool time_t_is_inside_period(time_t entryTime, time_t startTime, time_t endTime)
{    
    tm *a = localtime(&entryTime);
    tm _entryTime;
    _entryTime.tm_year = a->tm_year;
    _entryTime.tm_mon = a->tm_mon;
    _entryTime.tm_mday = a->tm_mday;
    _entryTime.tm_wday = a->tm_wday;
    _entryTime.tm_hour = a->tm_hour;
    _entryTime.tm_min = a->tm_min;
    _entryTime.tm_sec = a->tm_sec;
    
    tm *b = localtime(&startTime);
    tm _startTime;
    _startTime.tm_year = b->tm_year;
    _startTime.tm_mon = b->tm_mon;
    _startTime.tm_mday = b->tm_mday;
    _startTime.tm_wday = b->tm_wday;
    _startTime.tm_hour = b->tm_hour;
    _startTime.tm_min = b->tm_min;
    _startTime.tm_sec = b->tm_sec;
    
    tm *c = localtime(&endTime);
    tm _endTime;
    _endTime.tm_year = c->tm_year;
    _endTime.tm_mon = c->tm_mon;
    _endTime.tm_mday = c->tm_mday;
    _endTime.tm_wday = c->tm_wday;
    _endTime.tm_hour = c->tm_hour;
    _endTime.tm_min = c->tm_min;
    _endTime.tm_sec = c->tm_sec;
    if(_startTime.tm_year > 100 && _endTime.tm_year > 100)
    {
        if(endTime > startTime && entryTime >= startTime && entryTime < endTime)
        {
            return true;
        }
        else if(endTime == startTime && entryTime >= startTime && entryTime < startTime + 86400)
        {
            return true;
        }
        else 
            return false;
    }    
    else if((entryTime >= startTime && entryTime < endTime) || (startTime == endTime && _startTime.tm_year == 100 && _startTime.tm_mon == 0 && _startTime.tm_mday == 1))
    {
        return true;
    }
    else if(_startTime.tm_year == 100 && _startTime.tm_mon == 0 && _startTime.tm_mday == 1 && _endTime.tm_year == 100 && _endTime.tm_mon == 0 && _endTime.tm_mday == 1)
    {
        tm _entry_base_hour;
        _entry_base_hour.tm_year = 100;
        _entry_base_hour.tm_mon = 0;
        _entry_base_hour.tm_mday = 1;
        _entry_base_hour.tm_hour = _entryTime.tm_hour;
        _entry_base_hour.tm_min = _entryTime.tm_min;
        _entry_base_hour.tm_sec = _entryTime.tm_sec;
        time_t entry_base_hour = _mktime_slow(&_entry_base_hour);
        if(entry_base_hour >= startTime && entry_base_hour < endTime && startTime <= endTime)
            return true;
        else if(entry_base_hour >= startTime && !(entry_base_hour < endTime) && startTime > endTime)
            return true;
        else if(!(entry_base_hour >= startTime) && entry_base_hour < endTime && startTime > endTime)
            return true;
        else
            return false;
    }
    else if(_startTime.tm_year == _endTime.tm_year && _startTime.tm_mon == _endTime.tm_mon && _startTime.tm_mday == _endTime.tm_mday)
    {
        tm _entry_base_hour;
        _entry_base_hour.tm_year = _startTime.tm_year;
        _entry_base_hour.tm_mon = _startTime.tm_mon;
        _entry_base_hour.tm_mday = _startTime.tm_mday;
        _entry_base_hour.tm_hour = _entryTime.tm_hour;
        _entry_base_hour.tm_min = _entryTime.tm_min;
        _entry_base_hour.tm_sec = _entryTime.tm_sec;
        time_t entry_base_hour = _mktime_slow(&_entry_base_hour);
        if(entry_base_hour >= startTime && entry_base_hour < endTime && startTime <= endTime)
            return true;
        else if(entry_base_hour >= startTime && !(entry_base_hour < endTime) && startTime > endTime)
            return true;
        else if(!(entry_base_hour >= startTime) && entry_base_hour < endTime && startTime > endTime)
            return true;
        else
            return false;
    }
    else if(_startTime.tm_year == 100 && _startTime.tm_mon == 1 && _endTime.tm_year == 100 && _endTime.tm_mon == 1)
    {
        if(_entryTime.tm_wday == 0)
        {
             if(_entryTime.tm_wday + 7 >= _startTime.tm_mday && _entryTime.tm_wday + 7 <= _endTime.tm_mday)
                {
                    tm _entry_Week_day;
                    _entry_Week_day.tm_year = 100;
                    _entry_Week_day.tm_mon = 1;
                    _entry_Week_day.tm_mday = 1;
                    _entry_Week_day.tm_hour = _entryTime.tm_hour;
                    _entry_Week_day.tm_min = _entryTime.tm_min;
                    _entry_Week_day.tm_sec = _entryTime.tm_sec;
                    time_t entry_base_wday = _mktime_slow(&_entry_Week_day);
                    if(_startTime.tm_hour < _endTime.tm_hour && _entry_Week_day.tm_hour >= _startTime.tm_hour && _entry_Week_day.tm_hour < _endTime.tm_hour)
                    {
                        return true;
                    }
                    else if(_startTime.tm_hour > _endTime.tm_hour && (_entry_Week_day.tm_hour >= _startTime.tm_hour || _entry_Week_day.tm_hour < _endTime.tm_hour))
                    {
                        return true;
                    }
                    else
                        return false;
                }
            else
                return false;
        }
        else
        {
            if(_entryTime.tm_wday >= _startTime.tm_mday && _entryTime.tm_wday <= _endTime.tm_mday)
                {
                    
                    tm _entry_Week_day;
                    _entry_Week_day.tm_year = 100;
                    _entry_Week_day.tm_mon = 1;
                    _entry_Week_day.tm_mday = 1;
                    _entry_Week_day.tm_hour = _entryTime.tm_hour;
                    _entry_Week_day.tm_min = _entryTime.tm_min;
                    _entry_Week_day.tm_sec = _entryTime.tm_sec;
                    time_t entry_base_wday = _mktime_slow(&_entry_Week_day);
                    if(_startTime.tm_hour < _endTime.tm_hour && _entry_Week_day.tm_hour >= _startTime.tm_hour && _entry_Week_day.tm_hour < _endTime.tm_hour)
                    {
                        return true;
                    }
                    else if(_startTime.tm_hour > _endTime.tm_hour && (_entry_Week_day.tm_hour >= _startTime.tm_hour || _entry_Week_day.tm_hour < _endTime.tm_hour))
                    {
                        return true;
                    }
                    else
                        return false;
                }
            else
                return false;
        }
    }
    else
        return false;
}

void delete_week_day(parking_period &_parking_period ,time_t startTime, time_t endTime)
{
    tm *b = localtime(&startTime);
    tm _startTime;
    _startTime.tm_year = b->tm_year;
    _startTime.tm_mon = b->tm_mon;
    _startTime.tm_mday = b->tm_mday;
    _startTime.tm_wday = b->tm_wday;
    _startTime.tm_hour = b->tm_hour;
    _startTime.tm_min = b->tm_min;
    _startTime.tm_sec = b->tm_sec;
    
    tm *c = localtime(&endTime);
    tm _endTime;
    _endTime.tm_year = c->tm_year;
    _endTime.tm_mon = c->tm_mon;
    _endTime.tm_mday = c->tm_mday;
    _endTime.tm_wday = c->tm_wday;
    _endTime.tm_hour = c->tm_hour;
    _endTime.tm_min = c->tm_min;
    _endTime.tm_sec = c->tm_sec;
    
    for(int i = 0; i < _parking_period.parking_days.size(); i++)
    {       
        if(_parking_period.parking_days[i].weekday == 0)
        {
            if(_parking_period.parking_days[i].weekday + 7 >= _startTime.tm_mday && _parking_period.parking_days[i].weekday + 7 <= _endTime.tm_mday)
            {
                _parking_period.total_period -= _parking_period.parking_days[i].day_period;
                _parking_period.parking_days.erase(_parking_period.parking_days.begin() + i);
                i--;
            }
        }
        else
        {
            if(_parking_period.parking_days[i].weekday >= _startTime.tm_mday && _parking_period.parking_days[i].weekday <= _endTime.tm_mday)
            {
                _parking_period.total_period -= _parking_period.parking_days[i].day_period;
                _parking_period.parking_days.erase(_parking_period.parking_days.begin() + i);
                i--;
            }
        }
    }
    tm _entryTime;
    _entryTime.tm_year = _parking_period.parking_days[0].year;
    _entryTime.tm_mon = _parking_period.parking_days[0].month;
    _entryTime.tm_mday = _parking_period.parking_days[0].month_day;
    _entryTime.tm_hour = _parking_period.parking_days[0].all_hour_in_day[0].hour;
    _entryTime.tm_min = 60 - _parking_period.parking_days[0].all_hour_in_day[0].minute - 1;
    if(_parking_period.parking_days[0].all_hour_in_day[0].second == 0)
    {
        _entryTime.tm_min ++;
        _entryTime.tm_sec = 0;
    }
    else
    {
        _entryTime.tm_sec = 60 - _parking_period.parking_days[0].all_hour_in_day[0].second;
    }
    _parking_period.entryTime = _mktime_slow(&_entryTime);
}

int get_parking_cost(parking_period _parking_period)
{
    int total_period = _parking_period.total_period;
    int total_amount = 0;
    int current_step = 0;
    int max;
    int enter_main_loop = 1;
    bool increase_by_next = false;
    
    //std::cout << total_period << "\n";
    //std::cout << "block_list.size() = " << block_list.size() << "\n";
    do
    {
        increase_by_next = false;
        Block currentBlock = block_list[current_step];
        if(!time_t_is_inside_period(_parking_period.entryTime, currentBlock.startTime, currentBlock.endTime))
        {
            //std::cout << "not between startTime and endTime for block_list[" << current_step << "] \n"; 
            if(currentBlock.type == Normal) 
            {
                tm *b = localtime(&currentBlock.startTime);
                tm _startTime;
                _startTime.tm_year = b->tm_year;
                _startTime.tm_mon = b->tm_mon;
                _startTime.tm_mday = b->tm_mday;
                _startTime.tm_wday = b->tm_wday;
                _startTime.tm_hour = b->tm_hour;
                _startTime.tm_min = b->tm_min;
                _startTime.tm_sec = b->tm_sec;
                
                tm *c = localtime(&currentBlock.endTime);
                tm _endTime;
                _endTime.tm_year = c->tm_year;
                _endTime.tm_mon = c->tm_mon;
                _endTime.tm_mday = c->tm_mday;
                _endTime.tm_wday = c->tm_wday;
                _endTime.tm_hour = c->tm_hour;
                _endTime.tm_min = c->tm_min;
                _endTime.tm_sec = c->tm_sec;
                if(_startTime.tm_year == 100 && _startTime.tm_mon == 1 && _endTime.tm_year == 100 && _endTime.tm_mon == 1)
                {
                    delete_week_day(_parking_period ,currentBlock.startTime, currentBlock.endTime);
                    total_period = _parking_period.total_period;
                }
                current_step++;
            }
            else if(currentBlock.type == Sub_amount_start) 
                current_step = (block_list[currentBlock.next].next == 255) ? currentBlock.next + 1 : block_list[currentBlock.next].next;
            //std::cout << "then we move to block_list[" << current_step << "] \n"; 
        }
        else
        {
            //std::cout << "between startTime and endTime for block_list[" << current_step << "] \n"; 
            if(currentBlock.type == Normal)
            {
                //std::cout << "block_list[" << current_step << "] == Normal \n";
                //std::cout << "compare (total period = " << total_period << ") and " 
                //          << "(block_list[" << current_step << "].period = " << currentBlock.period 
                //          << ") by (relation = " << print_Relation(currentBlock.relation) << ") "
                //          << " is " << compare(total_period, currentBlock.period, currentBlock.relation) <<"\n";
                if(compare(total_period, currentBlock.period, currentBlock.relation))
                {
                    total_amount += currentBlock.amount;
                    tm *b = localtime(&currentBlock.startTime);
                    tm _startTime;
                    _startTime.tm_year = b->tm_year;
                    _startTime.tm_mon = b->tm_mon;
                    _startTime.tm_mday = b->tm_mday;
                    _startTime.tm_wday = b->tm_wday;
                    _startTime.tm_hour = b->tm_hour;
                    _startTime.tm_min = b->tm_min;
                    _startTime.tm_sec = b->tm_sec;
                    
                    tm *c = localtime(&currentBlock.endTime);
                    tm _endTime;
                    _endTime.tm_year = c->tm_year;
                    _endTime.tm_mon = c->tm_mon;
                    _endTime.tm_mday = c->tm_mday;
                    _endTime.tm_wday = c->tm_wday;
                    _endTime.tm_hour = c->tm_hour;
                    _endTime.tm_min = c->tm_min;
                    _endTime.tm_sec = c->tm_sec;
                    if(_startTime.tm_year > 100 && _endTime.tm_year > 100)
                    {
                        delete_period(_parking_period ,_parking_period.parking_days[0].day_period);
                        total_period = _parking_period.total_period;
                        current_step = 0;
                    }
                    else if(_startTime.tm_year == 100 && _startTime.tm_mon == 1 && _endTime.tm_year == 100 && _endTime.tm_mon == 1)
                    {
                        delete_week_day(_parking_period ,currentBlock.startTime, currentBlock.endTime);
                        total_period = _parking_period.total_period;
                        current_step = 0;
                    }
                    else
                    {
                        if(currentBlock.deduct)
                        {
                            tm *a = localtime(&_parking_period.entryTime);
                            tm _entryTime;
                            _entryTime.tm_year = 100;
                            _entryTime.tm_mon = 0;
                            _entryTime.tm_mday = 1;
                            _entryTime.tm_hour = a->tm_hour;
                            _entryTime.tm_min = a->tm_min;
                            _entryTime.tm_sec = a->tm_sec;
                            time_t new_entryTime = _mktime_slow(&_entryTime);
                            if((int)std::difftime(currentBlock.endTime, new_entryTime) > 0)
                            {
                                if(currentBlock.startTime > currentBlock.endTime)
                                {   
                                    total_period -= std::min(currentBlock.period,(int)std::difftime(currentBlock.endTime, new_entryTime));
                                    delete_period(_parking_period ,std::min(currentBlock.period,(int)std::difftime(currentBlock.endTime, new_entryTime)));
                                }
                                else
                                {   
                                    total_period -= currentBlock.period;
                                    delete_period(_parking_period ,currentBlock.period);
                                }
                            }
                            else
                            {
                                if(currentBlock.startTime > currentBlock.endTime)
                                {
                                    total_period -= std::min(currentBlock.period,((int)std::difftime(currentBlock.endTime, new_entryTime) + 86400));
                                    delete_period(_parking_period ,std::min(currentBlock.period,((int)std::difftime(currentBlock.endTime, new_entryTime) + 86400)));
                                }
                                else
                                {   
                                    total_period -= currentBlock.period;
                                    delete_period(_parking_period ,currentBlock.period);
                                }
                            }

                            //std::cout << "total_period = " << total_period << "\n";
                            //std::cout << "total_amount = " << total_amount << "\n";
                        }
                        current_step = (currentBlock.next == 255) ? current_step + 1 : currentBlock.next;
                        
                    }
                }
                else
                {
                    current_step++;
                }
            }
            else if(currentBlock.type == Sub_amount_start)
            {
                //std::cout << "block_list[" << current_step << "] == Sub_amount_start \n";
                max = block_list[currentBlock.next].max_amount == 0 ? 0x7FFFFFFF : block_list[currentBlock.next].max_amount;
                int maxPeriod = block_list[currentBlock.next].period;
                int subPeriod = 0;
                int i = 1;
                int subAmount = 0;
                //std::cout << "compare (total period = " << total_period << ") and " 
                //              << "(block_list[" << current_step << "].period = " << maxPeriod 
                //              << ") by (relation = " << print_Relation(block_list[currentBlock.next].relation) << ") "
                //              << " is " << compare(total_period, maxPeriod, block_list[currentBlock.next].relation) <<"\n";
                if(!compare(total_period, maxPeriod, block_list[currentBlock.next].relation))
                {
                    current_step = (block_list[currentBlock.next].next == 255) ? currentBlock.next + 1 : block_list[currentBlock.next].next;
                //    std::cout << "not enter loop with current_step = " << current_step << "\n";
                }
                else
                {
                    while (current_step + i < currentBlock.next && total_period > 0)
                    {
                        //std::cout << "compare (total period = " << total_period << ") and " 
                        //      << "(block_list[" << current_step << "].period = " << currentBlock.period 
                        //      << ") by (relation = " << print_Relation(currentBlock.relation) << ") "
                        //      << " is " << compare(total_period, currentBlock.period, currentBlock.relation) << "\n";
                        if(compare(total_period, block_list[current_step + i].period, block_list[current_step + i].relation))
                        {
                            //std::cout << "relation Correct for block[" << current_step << "]\n"; 
                            //std::cout << "current_step + i = " << current_step + i << "\n"; 
                            subAmount += block_list[current_step + i].amount;
                            total_period -= block_list[current_step + i].period;
                            delete_period(_parking_period ,block_list[current_step + i].period);
                            subPeriod += block_list[current_step + i].period;
                            //std::cout << "total_period = " << total_period << "\n";
                            //std::cout << "subAmount = " << subAmount << "\n";
                            if(!time_t_is_inside_period(_parking_period.entryTime, block_list[current_step].startTime, block_list[current_step].endTime))
                            {
                                current_step = (block_list[currentBlock.next].next == 255) ? currentBlock.next + 1 : block_list[currentBlock.next].next;
                                //std::cout << "end loop with current_step = " << current_step << "\n";
                                break;
                            }
                        }
                        else
                        {
                            i++;
                        }
                    }
                    if (subAmount > max) subAmount = max;
                    total_amount += subAmount;
                    //std::cout << "total_period = " << total_period << "\n";
                    //std::cout << "total_amount = " << total_amount << "\n";
                }
            }
            else if(currentBlock.type == Sub_amount_end)
            {
                current_step = (currentBlock.next == 255) ? current_step + 1 : currentBlock.next;
            }
            if (total_period <= 0) break;
        }
    } 
    while (current_step < block_list.size() && total_period > 0);
    return total_amount;
}

time_t hour_to_datetime(hour_in_day time)
{
    tm time_t_Time;
    time_t_Time.tm_year = 100;
    time_t_Time.tm_mon = 0;
    time_t_Time.tm_mday = 1;
    time_t_Time.tm_hour = time.hour;
    time_t_Time.tm_min = time.minute;
    time_t_Time.tm_sec = time.second;
    time_t output = mktime(&time_t_Time);
    return output;
}

time_t week_day_to_datetime(int week_day, hour_in_day time)
{
    tm time_t_Time;
    time_t_Time.tm_year = 100;
    time_t_Time.tm_mon = 1;
    time_t_Time.tm_mday = (week_day == 0) ? 7 : week_day;
    time_t_Time.tm_hour = time.hour;
    time_t_Time.tm_min = time.minute;
    time_t_Time.tm_sec = time.second;
    time_t output = mktime(&time_t_Time);
    return output;
}


void parameters_to_rules(int free_time, bool include_free_time, hour_in_day start_period_1, hour_in_day end_period_1, hour_in_day start_period_2, hour_in_day end_period_2, int first_period, int cost_first_period, int part_first_period, int cost_after, int period_after, int daily_max, int Fixed_1, int Fixed_2, int week_day_charging_start, int week_day_charging_end, std::vector<time_t> day_off)
{
    if(day_off.size() == 0 && week_day_charging_start == -1 && week_day_charging_end == -1 && start_period_2.hour == -1 && end_period_2.hour == -1) // mode 1, 2, 3
    {        
        if(start_period_1.hour == end_period_1.hour && start_period_1.minute == end_period_1.minute && start_period_1.second == end_period_1.second)
        {
            Block current_step(0, Normal, 0, LessOrEqual, 0, 0, 0, 0, 0, 0);
            current_step.srNo = 0;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(start_period_1);
            current_step.endTime = hour_to_datetime(end_period_1);
            current_step.relation = LessOrEqual;
            current_step.deduct = 1;
            current_step.cross_period = 1;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 255;
            if(include_free_time)
            {
                current_step.period = free_time;
            }
            else
            {
                current_step.period = 0;
            }
            block_list.push_back(current_step);
            if(part_first_period == -1 || first_period == part_first_period) // mode 1 || mode 2
            {
                current_step.srNo = 1;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.next = 4;
                current_step.period = 86400;
                block_list.push_back(current_step);
                current_step.srNo = 2;
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = daily_max;
                current_step.next = 2;
                block_list.push_back(current_step);
                current_step.srNo = 3;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.amount = 0;
                current_step.next = 10;
                block_list.push_back(current_step);
                current_step.srNo = 4;
                current_step.relation = LessOrEqual;
                current_step.deduct = 1;
                current_step.period = first_period;
                current_step.amount = cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 5;
                current_step.relation = Great;
                current_step.next = 6;
                block_list.push_back(current_step);
                current_step.srNo = 6;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.amount = 0;
                current_step.next = 9;
                block_list.push_back(current_step);
                current_step.srNo = 7;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.next = 7;
                block_list.push_back(current_step);
                current_step.srNo = 8;
                current_step.relation = Less;
                current_step.next = 9;
                block_list.push_back(current_step);
                current_step.srNo = 9;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max - cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 10;
                current_step.type = Sub_amount_start;
                current_step.max_amount = daily_max;
                current_step.next = 13;
                block_list.push_back(current_step);
                current_step.srNo = 11;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.max_amount = 0;
                current_step.next = 11;
                block_list.push_back(current_step);
                current_step.srNo = 12;
                current_step.relation = Less;
                current_step.next = 13;
                block_list.push_back(current_step);
                current_step.srNo = 13;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
                
            }
            else // mode 3
            {
                current_step.srNo = 1;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.next = 4;
                current_step.period = 86400;
                block_list.push_back(current_step);
                current_step.srNo = 2;
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = daily_max;
                current_step.next = 2;
                block_list.push_back(current_step);
                current_step.srNo = 3;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.amount = 0;
                current_step.next = 13;
                block_list.push_back(current_step);
                current_step.srNo = 4;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.deduct = 1;
                current_step.next = 7;
                block_list.push_back(current_step);
                current_step.srNo = 5;
                current_step.type = Normal;
                current_step.period = part_first_period;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_first_period;
                current_step.next = 5;
                block_list.push_back(current_step);
                current_step.srNo = 6;
                current_step.relation = Less;
                current_step.next = 7;
                block_list.push_back(current_step);
                current_step.srNo = 7;
                current_step.type = Sub_amount_end;
                current_step.period = first_period;
                current_step.relation = LessOrEqual;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 8;
                current_step.type = Normal;
                current_step.period = first_period;
                current_step.relation = Great;
                current_step.amount = (first_period / part_first_period) * cost_first_period;
                current_step.max_amount = daily_max;
                current_step.next = 9;
                block_list.push_back(current_step);
                current_step.srNo = 9;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = 0;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 10;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.next = 10;
                block_list.push_back(current_step);
                current_step.srNo = 11;
                current_step.relation = Less;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 12;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max - (first_period / part_first_period) * cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 13;
                current_step.type = Sub_amount_start;
                current_step.max_amount = daily_max;
                current_step.next = 16;
                block_list.push_back(current_step);
                current_step.srNo = 14;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.max_amount = 0;
                current_step.next = 14;
                block_list.push_back(current_step);
                current_step.srNo = 15;
                current_step.relation = Less;
                current_step.next = 16;
                block_list.push_back(current_step);
                current_step.srNo = 16;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
            }
        }
        else
        {
            Block current_step(0, Normal, 0, LessOrEqual, 0, 0, 0, 0, 0, 0);
            current_step.srNo = 0;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(start_period_1);
            current_step.endTime = hour_to_datetime(end_period_1);
            current_step.relation = LessOrEqual;
            current_step.deduct = 1;
            current_step.cross_period = 1;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 255;
            if(include_free_time)
            {
                current_step.period = free_time;
            }
            else
            {
                current_step.period = 0;
            }
            block_list.push_back(current_step);
            
            if(part_first_period == -1 || first_period == part_first_period) // mode 1 || mode 2
            {
                current_step.srNo = 1;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.next = 6;
                current_step.period = 86400;
                block_list.push_back(current_step);
                current_step.srNo = 2;
                current_step.startTime = hour_to_datetime(end_period_1);
                current_step.endTime = hour_to_datetime(start_period_1);
                current_step.period = (current_step.endTime > current_step.startTime) ? std::difftime(current_step.endTime, current_step.startTime) : 86400 - std::difftime(current_step.startTime, current_step.endTime);
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = 0;
                current_step.next = 6;
                block_list.push_back(current_step);
                current_step.srNo = 3;
                current_step.relation = Less;
                current_step.deduct = 1;
                block_list.push_back(current_step);
                current_step.srNo = 4;
                current_step.startTime = hour_to_datetime(start_period_1);
                current_step.endTime = hour_to_datetime(end_period_1);
                current_step.relation = GreatOrEqual;
                current_step.period = 86400;
                current_step.deduct = 1;
                current_step.amount = daily_max;
                current_step.next = 4;
                block_list.push_back(current_step);
                current_step.srNo = 5;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.amount = 0;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 6;
                current_step.relation = LessOrEqual;
                current_step.deduct = 1;
                current_step.period = first_period;
                current_step.amount = cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 7;
                current_step.relation = Great;
                current_step.next = 8;
                block_list.push_back(current_step);
                current_step.srNo = 8;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.amount = 0;
                current_step.next = 11;
                block_list.push_back(current_step);
                current_step.srNo = 9;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.next = 9;
                block_list.push_back(current_step);
                current_step.srNo = 10;
                current_step.relation = Less;
                current_step.next = 11;
                block_list.push_back(current_step);
                current_step.srNo = 11;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max - cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 12;
                current_step.type = Sub_amount_start;
                current_step.max_amount = daily_max;
                current_step.next = 15;
                block_list.push_back(current_step);
                current_step.srNo = 13;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.max_amount = 0;
                current_step.next = 13;
                block_list.push_back(current_step);
                current_step.srNo = 14;
                current_step.relation = Less;
                current_step.next = 15;
                block_list.push_back(current_step);
                current_step.srNo = 15;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 16;
                current_step.type = Normal;   
                current_step.startTime = hour_to_datetime(end_period_1);
                current_step.endTime = hour_to_datetime(start_period_1);
                current_step.period = (current_step.endTime > current_step.startTime) ? std::difftime(current_step.endTime, current_step.startTime) : 86400 - std::difftime(current_step.startTime, current_step.endTime);
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = 0;
                current_step.max_amount = 0;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 17;
                current_step.relation = Less;
                current_step.deduct = 1;
                block_list.push_back(current_step);
            }
            else // mode 3
            {
                current_step.srNo = 1;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.next = 4;
                current_step.period = 86400;
                block_list.push_back(current_step);
                current_step.srNo = 2;
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = daily_max;
                current_step.next = 2;
                block_list.push_back(current_step);
                current_step.srNo = 3;
                current_step.relation = Less;
                current_step.deduct = 0;
                current_step.amount = 0;
                current_step.next = 13;
                block_list.push_back(current_step);
                current_step.srNo = 4;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.deduct = 1;
                current_step.next = 7;
                block_list.push_back(current_step);
                current_step.srNo = 5;
                current_step.type = Normal;
                current_step.period = part_first_period;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_first_period;
                current_step.next = 5;
                block_list.push_back(current_step);
                current_step.srNo = 6;
                current_step.relation = Less;
                current_step.next = 7;
                block_list.push_back(current_step);
                current_step.srNo = 7;
                current_step.type = Sub_amount_end;
                current_step.period = first_period;
                current_step.relation = LessOrEqual;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 8;
                current_step.type = Normal;
                current_step.period = first_period;
                current_step.relation = Great;
                current_step.amount = (first_period / part_first_period) * cost_first_period;
                current_step.max_amount = daily_max;
                current_step.next = 9;
                block_list.push_back(current_step);
                current_step.srNo = 9;
                current_step.type = Sub_amount_start;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = 0;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 10;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.next = 10;
                block_list.push_back(current_step);
                current_step.srNo = 11;
                current_step.relation = Less;
                current_step.next = 12;
                block_list.push_back(current_step);
                current_step.srNo = 12;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max - (first_period / part_first_period) * cost_first_period;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 13;
                current_step.type = Sub_amount_start;
                current_step.max_amount = daily_max;
                current_step.next = 16;
                block_list.push_back(current_step);
                current_step.srNo = 14;
                current_step.type = Normal;
                current_step.period = period_after;
                current_step.relation = GreatOrEqual;
                current_step.amount = cost_after;
                current_step.max_amount = 0;
                current_step.next = 14;
                block_list.push_back(current_step);
                current_step.srNo = 15;
                current_step.relation = Less;
                current_step.next = 16;
                block_list.push_back(current_step);
                current_step.srNo = 16;
                current_step.type = Sub_amount_end;
                current_step.period = 0;
                current_step.relation = Great;
                current_step.amount = 0;
                current_step.max_amount = daily_max;
                current_step.next = 255;
                block_list.push_back(current_step);
                current_step.srNo = 16;
                current_step.type = Normal;   
                current_step.startTime = hour_to_datetime(end_period_1);
                current_step.endTime = hour_to_datetime(start_period_1);
                current_step.period = (current_step.endTime > current_step.startTime) ? std::difftime(current_step.endTime, current_step.startTime) : 86400 - std::difftime(current_step.startTime, current_step.endTime);
                current_step.relation = GreatOrEqual;
                current_step.deduct = 1;
                current_step.amount = 0;
                current_step.max_amount = 0;
                current_step.next = 1;
                block_list.push_back(current_step);
                current_step.srNo = 18;
                current_step.relation = Less;
                block_list.push_back(current_step);
            }
        }
    }
    else
    {
        if(start_period_2.hour == -1 && end_period_2.hour == -1) // mode 4
        {
            hour_in_day new_start_period_1; new_start_period_1.hour = 0; new_start_period_1.minute = 0; new_start_period_1.second = 0;
            Block current_step(0, Normal, 0, LessOrEqual, 0, 0, 0, 0, 0, 0);
            current_step.srNo = 0;
            current_step.type = Normal;        
            current_step.startTime = week_day_to_datetime((week_day_charging_end + 1) % 7, new_start_period_1);
            current_step.endTime = week_day_to_datetime((week_day_charging_start - 1 ) % 7, new_start_period_1);
            current_step.period = 86400;
            current_step.relation = GreatOrEqual;
            current_step.deduct = 1;
            current_step.cross_period = 0;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 0;
            block_list.push_back(current_step);
            current_step.srNo = 1;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(new_start_period_1);
            current_step.endTime = hour_to_datetime(new_start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.deduct = 0;
            current_step.cross_period = 1;
            current_step.next = 12;
            block_list.push_back(current_step);
            current_step.srNo = 2;
            current_step.type = Sub_amount_start;        
            current_step.startTime = week_day_to_datetime(week_day_charging_start, end_period_1);
            current_step.endTime = week_day_to_datetime(week_day_charging_end, start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.deduct = 1;
            current_step.cross_period = 0;
            current_step.next = 5;
            block_list.push_back(current_step);
            current_step.srNo = 3;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(end_period_1);
            current_step.endTime = hour_to_datetime(start_period_1);
            current_step.period = 3600;
            current_step.relation = Great;
            current_step.deduct = 1;
            current_step.next = 3;
            block_list.push_back(current_step);
            current_step.srNo = 4;
            current_step.type = Normal;        
            current_step.relation = LessOrEqual;
            current_step.deduct = 1;
            current_step.next = 5;
            block_list.push_back(current_step);
            current_step.srNo = 5;
            current_step.type = Sub_amount_end; 
            current_step.startTime = week_day_to_datetime(week_day_charging_start, end_period_1);
            current_step.endTime = week_day_to_datetime(week_day_charging_end, start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.amount = 0;
            current_step.max_amount = daily_max;
            current_step.next = 6;
            block_list.push_back(current_step);
            current_step.srNo = 6;
            current_step.type = Sub_amount_start;        
            current_step.startTime = week_day_to_datetime(week_day_charging_start, start_period_1);
            current_step.endTime = week_day_to_datetime(week_day_charging_end, end_period_1);
            current_step.period = 0;
            current_step.deduct = 1;
            current_step.cross_period = 1;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 9;
            block_list.push_back(current_step);
            current_step.srNo = 7;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(start_period_1);
            current_step.endTime = hour_to_datetime(end_period_1);
            current_step.period = 3600;
            current_step.relation = GreatOrEqual;
            current_step.deduct = 1;
            current_step.amount = Fixed_1;
            current_step.next = 7;
            block_list.push_back(current_step);
            current_step.srNo = 8;
            current_step.type = Normal;        
            current_step.relation = Less;
            current_step.deduct = 1;
            current_step.next = 9;
            block_list.push_back(current_step);
            current_step.srNo = 9;
            current_step.type = Sub_amount_end; 
            current_step.startTime = week_day_to_datetime(week_day_charging_start, end_period_1);
            current_step.endTime = week_day_to_datetime(week_day_charging_end, start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.amount = 0;
            current_step.max_amount = daily_max;
            current_step.next = 12;
            block_list.push_back(current_step);
            current_step.srNo = 10;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(new_start_period_1);
            current_step.endTime = hour_to_datetime(new_start_period_1);
            current_step.period = 3600;
            current_step.relation = GreatOrEqual;
            current_step.deduct = 1;
            current_step.amount = 0;
            current_step.max_amount = 0;
            block_list.push_back(current_step);
            current_step.srNo = 11;
            current_step.relation = Less;
            block_list.push_back(current_step);
            for(int i = 0; i < day_off.size(); i++)
            {
                current_step.srNo = 12 + i;
                current_step.type = Normal; 
                current_step.startTime = day_off[i];
                current_step.endTime = day_off[i];
                current_step.period = 0;
                current_step.relation = Great;
                current_step.deduct = 0;
                current_step.amount = 0;
                current_step.max_amount = 0;
                current_step.next = 6;
                block_list.push_back(current_step);
                
            }
            current_step.srNo = 12 + day_off.size();
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(new_start_period_1);
            current_step.endTime = hour_to_datetime(new_start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.deduct = 0;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 2;
            block_list.push_back(current_step);
            
        }
        else // mode 5
        {
            hour_in_day new_start_period_1; new_start_period_1.hour = 0; new_start_period_1.minute = 0; new_start_period_1.second = 0;
            Block current_step(0, Normal, 0, LessOrEqual, 0, 0, 0, 0, 0, 0);
            current_step.srNo = 0;
            current_step.type = Normal;        
            current_step.startTime = hour_to_datetime(new_start_period_1);
            current_step.endTime = hour_to_datetime(new_start_period_1);
            current_step.period = free_time;
            current_step.relation = LessOrEqual;
            current_step.deduct = 1;
            current_step.cross_period = 1;
            current_step.amount = 0;
            current_step.max_amount = 0;
            current_step.next = 255;
            block_list.push_back(current_step);
            current_step.srNo = 1;
            current_step.period = 86400;
            current_step.relation = GreatOrEqual;
            current_step.amount = daily_max;
            current_step.next = 1;
            block_list.push_back(current_step);
            current_step.srNo = 2;
            current_step.type = Sub_amount_start;
            current_step.relation = Great;
            current_step.period = 0;
            current_step.deduct = 0;
            current_step.amount = 0;
            current_step.next = 7;
            block_list.push_back(current_step);
            current_step.srNo = 3;
            current_step.type = Normal;
            current_step.startTime = hour_to_datetime(start_period_1);
            current_step.endTime = hour_to_datetime(end_period_1);
            current_step.relation = Less;
            current_step.period = (hour_to_datetime(end_period_1) > hour_to_datetime(start_period_1)) ? std::difftime(hour_to_datetime(end_period_1), hour_to_datetime(start_period_1)) : 86400 - std::difftime(hour_to_datetime(start_period_1), hour_to_datetime(end_period_1));
            current_step.deduct = 1;
            current_step.amount = Fixed_1;
            current_step.next = 5;
            block_list.push_back(current_step);
            current_step.srNo = 4;
            current_step.relation = GreatOrEqual;
            block_list.push_back(current_step);
            current_step.srNo = 5;
            current_step.type = Normal;
            current_step.startTime = hour_to_datetime(start_period_2);
            current_step.endTime = hour_to_datetime(end_period_2);
            current_step.relation = Less;
            current_step.period = (hour_to_datetime(end_period_2) > hour_to_datetime(start_period_2)) ? std::difftime(hour_to_datetime(end_period_2), hour_to_datetime(start_period_2)) : 86400 - std::difftime(hour_to_datetime(start_period_2), hour_to_datetime(end_period_2));
            current_step.amount = Fixed_2;
            current_step.next = 7;
            block_list.push_back(current_step);
            current_step.srNo = 6;
            current_step.relation = GreatOrEqual;
            block_list.push_back(current_step);
            current_step.srNo = 7;
            current_step.type = Sub_amount_end;
            current_step.startTime = hour_to_datetime(new_start_period_1);
            current_step.endTime = hour_to_datetime(new_start_period_1);
            current_step.period = 0;
            current_step.relation = Great;
            current_step.deduct = 0;
            current_step.amount = 0;
            current_step.max_amount = daily_max;
            current_step.next = 255;
            block_list.push_back(current_step);
        
        }
    }
}

