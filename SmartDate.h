//
// Created by dxxmwrld on 28.07.2021.
//

#ifndef ETUDE16_SMARTDATE_H
#define ETUDE16_SMARTDATE_H

#include <string>
class SmartDate {
public:
    int year_;
    int month_;
    int day_;
    int operator-(SmartDate rhs);
    SmartDate(int month, int day, int year);
    SmartDate();
    friend std::ostream& operator<<(std::ostream &out, const SmartDate &date);
};


#endif //ETUDE16_SMARTDATE_H
