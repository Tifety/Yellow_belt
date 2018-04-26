/*************************************************************************************//**
 *  @file       bus_manager.h
 *
 *  @brief      Brief description of bus_manager.h
 *
 *  @date       2018-04-25 09:37
 *         
 **************************************************************************************/

#pragma once
#include <string> 
#include <vector>
#include <iostream>
#include <map>
#include "responses.h"
class BusManager {
public:
    void AddBus(const std::string& bus, const std::vector<std::string>& stops);

    BusesForStopResponse GetBusesForStop(const std::string& stop) const;

    StopsForBusResponse GetStopsForBus(const std::string& bus) const;

    AllBusesResponse GetAllBuses() const;

    void Print_fucking_all ();
private:
    std:: map <std::string, std::vector <std::string>> buses_with_stops;
    std::map <std::string, std::vector <std::string>> stops_with_buses;

};

