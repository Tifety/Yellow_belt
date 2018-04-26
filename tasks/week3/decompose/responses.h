/*************************************************************************************//**
 *  @file       responses.h
 *
 *  @brief      Brief description of responses.h
 *
 *  @date       2018-04-25 09:14
 *         
 **************************************************************************************/


#pragma once
#include <vector>
#include <string> 
#include <map>
#include <iostream>
struct BusesForStopResponse {
  std::vector <std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    std::vector <std::string> stops;
    std::map <std::string, std::vector <std::string>> route_stops;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    std::map <std::string, std::vector <std::string>> all_buses;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);
