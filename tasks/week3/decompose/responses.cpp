/************************************************************************************//**
 *  @file       responses.cpp
 *
 *  @brief      Brief descriptinon of responses.cpp 
 *
 *  @date       2018-04-25 09:23
 *
 ***************************************************************************************/

#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
    if (r.buses.size()== 0) {
        os << "No stop";
    } else {
        for (const std::string & bus : r.buses) {
            os << bus << " ";
        }
    }
    return os;
}


std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
    if (r.route_stops.size() == 0) {
        os << "No bus";
    } else {
    bool first = true;
        for (const std::string& stop: r.stops) {
            if (first) {
                first = false;
            os << "Stop " << stop << ": "; 
            } else {
                os << std::endl << "Stop " << stop << ": ";
            }
            for (const auto& bus: r.route_stops.at(stop)) {
                os << bus << " ";
            }
        }
        }
    return os;
}
std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
    if (r.all_buses.size() == 0) {
        os << "No buses" ;
    } else {
        bool first = true;
        for (const auto& bus : r.all_buses) {
            if (first) {
                first = false;
                os << "Bus " << bus.first << ": ";
            } else {
            os << std::endl << "Bus " << bus.first << ": ";
            }
            for (const std::string & stop : bus.second) {
                os << stop << " ";
            }
        }
    }
    return os;
}
