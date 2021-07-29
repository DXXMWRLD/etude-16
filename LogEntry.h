//
// Created by dxxmwrld on 27.07.2021.
//

#ifndef ETUDE16_LOGENTRY_H
#define ETUDE16_LOGENTRY_H

#include <string>
#include "SmartDate.h"

class LogEntry {
public:
    SmartDate date_;
    std::string fuel_mark_;
    int mileage_;
    double cost_per_gallon_;
    double number_of_gallons_;
    double final_cost_;
    int mileage_between_stations_;
    double mileage_per_gallon_;
    double cost_per_mile_;
    double cost_per_day_;
    double consumption_time_of_gallon_;
    int days_;
    LogEntry(std::string log);
    LogEntry(LogEntry& rhs);
    LogEntry();
    void print();
    void printTitle();
};



#endif //ETUDE16_LOGENTRY_H
