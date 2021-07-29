cmake_minimum_required(VERSION 3.19)
project(etude16)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS date_time)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/content.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${Boost_INCLUDE_DIR})

add_executable(etude16 main.cpp LogEntry.cpp LogEntry.h ReportGeneration.cpp ReportGeneration.h SmartDate.cpp SmartDate.h Counter.cpp Counter.h)

target_link_libraries(etude16 Boost::date_time Boost::boost)