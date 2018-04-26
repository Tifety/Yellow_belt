/************************************************************************************//**
 *  @file       query.cpp
 *
 *  @brief      Brief descriptinon of query.cpp 
 *
 *  @date       2018-04-25 08:52
 *
 ***************************************************************************************/

#include "query.h"


std::istream& operator >> (std::istream& is, Query& q) {
  std::string  operation;
    is >> operation;
    if (operation == "NEW_BUS") {
        q.type=QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (std::string & st : q.stops) {
            is >> st;
        }
    } else if (operation == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (operation == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (operation == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}


