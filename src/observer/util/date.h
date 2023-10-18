#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "common/rc.h"
#include "sql/parser/value.h"

inline bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

inline RC string_to_date(std::string str, int32_t &date)
{
    int year = 0;
    int month = 0;
    int day = 0;
    int ret = sscanf(str.c_str(), "%d-%d-%d", &year, &month, &day);
    if (ret != 3) {
        return RC::INVALID_ARGUMENT;
    }

    // validate
    if (year < 1900 || year > 9999 || (month < 1 || month > 12) || (day < 1 || day > 31)){
        return RC::INVALID_ARGUMENT;
    } 

    int max_day_per_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int max_day = max_day_per_month[month - 1];
    if (day > max_day) {
        return RC::INVALID_ARGUMENT;
    }
    if (month == 2 && !is_leap_year(year) && day > 28) {
        return RC::INVALID_ARGUMENT;
    }

    date = year * 10000 + month * 100 + day;
    return RC::SUCCESS;
}

inline std::string date_to_string(int32_t date)
{
    std::stringstream ss;
    ss << date;
    return ss.str();
}

// inline const char * date_to_string(int32_t date)
// {
//     char buf[16] = {0};
//     snprintf(buf, sizeof(buf),"%04d-%02d-%02d", date/10000, (date%10000)/100, date%100);
//     return (const char *)&buf;
// }