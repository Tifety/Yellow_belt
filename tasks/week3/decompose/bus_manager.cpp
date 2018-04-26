/************************************************************************************//**
 *  @file       bus_manager.cpp
 *
 *  @brief      Brief descriptinon of bus_manager.cpp 
 *
 *  @date       2018-04-25 09:41
 *
 ***************************************************************************************/

#include "bus_manager.h"

    void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
        for (std::string stop : stops) {
            BusManager::buses_with_stops[bus].push_back(stop);
            BusManager::stops_with_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
        BusesForStopResponse answer;
        if (BusManager::stops_with_buses.count(stop)!= 0) {
            for (const std::string& bus : BusManager::stops_with_buses.at(stop)) {
                answer.buses.push_back(bus);
            }
        }
        return answer;
    }

    StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
        StopsForBusResponse answer;
        if (BusManager::buses_with_stops.count(bus) == 0) return answer;
        for (const auto & stop : BusManager::buses_with_stops.at(bus)) {
                answer.stops.push_back(stop);
            if (BusManager::stops_with_buses.at(stop).size() == 1) {
                answer.route_stops[stop].push_back("no interchange");
            } else {
                for (const auto& other_bus : BusManager::stops_with_buses.at(stop)) {
                    if (other_bus != bus)
                        answer.route_stops[stop].push_back(other_bus);
                }
            }
        }
        return answer;
    }

    AllBusesResponse BusManager::GetAllBuses() const {
        AllBusesResponse answer;
        for (const auto & bus : BusManager::buses_with_stops) {
            for (const std::string& stop : bus.second) {
                answer.all_buses[bus.first].push_back(stop);
            }
        }
        return answer;
    }

    void BusManager::Print_fucking_all () {
        std::cout << "BUSES:" << std::endl;
        for (auto item : BusManager::buses_with_stops) {
            std::cout << item.first << ": ";
            for (auto s : item.second) {
                std::cout << s << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "STOPS:" << std::endl;
        for (auto item : BusManager::stops_with_buses) {
            std::cout << item.first << ": ";
            for (auto a : item.second) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        }
    }
