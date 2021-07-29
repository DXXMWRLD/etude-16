//
// Created by dxxmwrld on 28.07.2021.
//

#ifndef ETUDE16_REPORTGENERATION_H
#define ETUDE16_REPORTGENERATION_H

#include <map>
#include "Counter.h"
#include "LogEntry.h"

class ReportGeneration {
private:
    std::map<std::string, Counter> data_;
public:
    void add_log(LogEntry log);
    ReportGeneration();
    void Report();
};


#endif //ETUDE16_REPORTGENERATION_H
