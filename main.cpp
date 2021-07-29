#include <iostream>
#include "LogEntry.h"
#include "SmartDate.h"
#include <fstream>
#include "ReportGeneration.h"
#include <iomanip>

int main() {
    std::ifstream text("content.txt");
    std::string line;
    if(text.is_open())
    {
        if(!text.eof())
            std::getline(text, line);
        LogEntry title;
        title.printTitle();
        if(!text.eof())
            std::getline(text, line);
        LogEntry previous_log(line);
        previous_log.print();
        LogEntry log;
        ReportGeneration report;
        while(std::getline(text, line))
        {
            log = LogEntry(line);
            log.days_ = log.date_ - previous_log.date_;
            log.mileage_between_stations_ = log.mileage_ - previous_log.mileage_;
            log.cost_per_day_ = log.final_cost_ / log.days_;
            log.cost_per_mile_ = log.final_cost_ / log.mileage_between_stations_;
            log.mileage_per_gallon_ = log.mileage_between_stations_ / log.number_of_gallons_;
            log.consumption_time_of_gallon_ = log.days_ / log.number_of_gallons_;
            log.print();
            report.add_log(log);
            previous_log = log;
        }
        std::cout << std::endl;
        report.Report();
    }
    text.close();
    return 0;
}
