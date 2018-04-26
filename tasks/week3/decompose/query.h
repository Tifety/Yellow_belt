/*************************************************************************************//**
 *  @file       query.h
 *
 *  @brief      Brief description of query.h
 *
 *  @date       2018-04-25 08:47
 *         
 **************************************************************************************/


#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) ;
