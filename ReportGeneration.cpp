//
// Created by dxxmwrld on 28.07.2021.
//

#include "ReportGeneration.h"
#include <iostream>
#include <iomanip>

ReportGeneration::ReportGeneration() = default;
void ReportGeneration::add_log(LogEntry log)
{
    ++data_[log.fuel_mark_].number_of_stations_;
    data_[log.fuel_mark_].number_of_gallons_ += log.number_of_gallons_;
    data_[log.fuel_mark_].mileage_ += log.mileage_between_stations_;
    data_[log.fuel_mark_].days_ += log.days_;
    data_[log.fuel_mark_].cost_ += log.final_cost_;
}
void ReportGeneration::Report()
{
    int mileage(0);
    double cost(0);
    int number_of_stations(0);
    double number_of_gallons(0);
    double days(0);
    std::cout << std::fixed << std::left << std::setw(27) << "Марка бензина" << std::setw(39) << "Количество заправок" << std::setw(62) << "Пробег между заправками (в милях)"
    << std::setw(48) << "Пробег на галлон (в милях)" << std::setw(29) << "Стоимость мили" << std::setw(27) << "Стоимость дня" << "Расход галлона (в днях)" <<std::endl;
    for(auto it = data_.begin(); it != data_.end(); ++it)
    {
        mileage += it->second.mileage_;
        cost += it->second.cost_;
        number_of_gallons += it->second.number_of_gallons_;
        number_of_stations += it->second.number_of_stations_;
        days += it->second.days_;
        std::cout << std::fixed << std::setprecision(1) << std::left << std::setw(15) << it->first << std::setprecision(2) << std::setw(21) << it->second.number_of_stations_
        << std::setw(35) << it->second.mileage_ << std::setw(28) << (it->second.mileage_ / it->second.number_of_gallons_) << std::setprecision(3) << "$" << std::setw(15)
        << (it->second.cost_ / it->second.mileage_) << "$" << std::setw(14) << (it->second.cost_ / it->second.days_) << std:: setprecision(2)
        << (it->second.days_ / it->second.number_of_gallons_) << std::endl;
    }
    std::cout.fill('-');
    std::cout << std::setw(154) << std::right << ' ' << std::endl;
    std::cout.fill(' ');
    std::cout << std::fixed << std::left << std::setw(23) << "Все марки" << std::setprecision(2) << std::setw(21) << number_of_stations
    << std::setw(35) << mileage << std::setw(28) << (mileage / number_of_gallons) << std::setprecision(3) << "$" << std::setw(15)
    << (cost / mileage) << "$" << std::setw(14) << (cost / days) << std:: setprecision(2)
    << (days / number_of_gallons) << std::endl;
}