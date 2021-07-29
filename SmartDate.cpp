//
// Created by dxxmwrld on 28.07.2021.
//

#include "SmartDate.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

int SmartDate::operator-(SmartDate rhs)
{
    int left_sum = day_;
    int right_sum = rhs.day_;
    int leap_year(0);
    if (year_ % 4 == 0)
        ++leap_year;
    std::vector<int> days_in_months({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    for (int i(0); i < month_ - 1; ++i)
    {
        left_sum += days_in_months[i];
    }
    if (month_ > 2)
        left_sum += leap_year;
    left_sum += std::ceil((year_ - 1) * 365.25);
    leap_year = 0;
    if(rhs.year_ % 4 == 0)
        ++leap_year;
    for (int i(0); i < rhs.month_ - 1; ++i)
    {
        right_sum += days_in_months[i];
    }
    if (rhs.month_ > 2)
        right_sum += leap_year;
    right_sum += ceil((rhs.year_ - 1) * 365.25);
    return (left_sum - right_sum) + 1;
}
SmartDate::SmartDate(int month, int day, int year):month_(month), day_(day), year_(year){}
SmartDate::SmartDate():month_(0), day_(0), year_(0){}
std::ostream& operator<<(std::ostream &out, const SmartDate &date)
{
    return out <<std::fixed << ((date.month_ > 9) ? std::to_string(date.month_) :  ("0" + std::to_string(date.month_))) << "/" << ((date.day_ > 9) ? std::to_string(date.day_) :  ("0" + std::to_string(date.day_))) << "/" << std::setw(5) <<date.year_;
}


