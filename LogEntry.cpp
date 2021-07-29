//
// Created by dxxmwrld on 27.07.2021.
//

#include "LogEntry.h"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>


LogEntry::LogEntry(std::string log): mileage_between_stations_(0), mileage_per_gallon_(0), cost_per_mile_(0), cost_per_day_(0), consumption_time_of_gallon_(0), days_(0)
{
    std::vector<std::string> splited_log;
    boost::split(splited_log, log, boost::is_any_of(" $"), boost::algorithm::token_compress_on);
    boost::spirit::qi::parse(splited_log[0].data(), splited_log[0].data() + splited_log[0].size(),
                             boost::spirit::qi::ushort_[ boost::phoenix::ref(date_.month_) = boost::spirit::qi::_1 ] >> boost::spirit::qi::char_('/')
                                                            >> boost::spirit::qi::ushort_[ boost::phoenix::ref(date_.day_) = boost::spirit::qi::_1 ] >> boost::spirit::qi::char_('/')
                                                            >> boost::spirit::qi::ushort_[ boost::phoenix::ref(date_.year_) = boost::spirit::qi::_1 ]);
    fuel_mark_ = splited_log[1];
    mileage_ = std::stoi(splited_log[2]);
    cost_per_gallon_ = std::stod(splited_log[3]);
    number_of_gallons_ = std::stod(splited_log[4]);
    final_cost_ = std::stod(splited_log[5]);
}
LogEntry::LogEntry(LogEntry &rhs) = default;
LogEntry::LogEntry() = default;
void LogEntry::print()
{
    std::cout << std::fixed << std::setprecision(1) << std::left << date_ << std::setw(16) << fuel_mark_ << std::setw(18)
    << mileage_ << std::setw(25) << cost_per_gallon_ << std::setw(21) << number_of_gallons_ << "$" << std::setprecision(2)
    << std::setw(7) << final_cost_ << std::setprecision(2) << std::setw(35) << mileage_between_stations_ << std::setw(28)
    << mileage_per_gallon_ << std::setprecision(3) << "$" << std::setw(15) << cost_per_mile_ << "$" << std::setw(14)
    << cost_per_day_ << std:: setprecision(2) << consumption_time_of_gallon_ << std::endl;
}
void LogEntry::printTitle()
{
    std::cout << std::fixed << std::left << std::setw(15) << "Дата" << std::setw(28) << "Марка бензина" << std::setw(30)
    << "Пробег (в милях)" << std::setw(43) << "Цена галлона (в центах)" << std::setw(39) << "Количество галлонов" << std::setw(13)
    << "Сумма" << std::setw(62) << "Пробег между заправками (в милях)" << std::setw(48) << "Пробег на галлон (в милях)" << std::setw(29)
    << "Стоимость мили" << std::setw(27) << "Стоимость дня" << "Расход галлона (в днях)" <<std::endl;
}


