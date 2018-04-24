#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string  operation;
    is >> operation;
    if (operation == "NEW_BUS") {
        q.type=QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (string & st : q.stops) {
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
struct BusesForStopResponse {
    vector <string> buses;
};


ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.size()== 0) {
        os << "No stop";
    } else {
        for (const string & bus : r.buses) {
            os << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    vector <string> stops;
    map <string, vector <string>> route_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.route_stops.size() == 0) {
        os << "No bus";
    } else {
    bool first = true;
        for (const string& stop: r.stops) {
            if (first) {
                first = false;
            os << "Stop " << stop << ": "; 
            } else {
                os << endl << "Stop " << stop << ": ";
            }
            for (const auto& bus: r.route_stops.at(stop)) {
                os << bus << " ";
            }
        }
        }
    return os;
}

struct AllBusesResponse {
    map <string, vector <string>> all_buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.all_buses.size() == 0) {
        os << "No buses" ;
    } else {
        bool first = true;
        for (const auto& bus : r.all_buses) {
            if (first) {
                first = false;
                os << "Bus " << bus.first << ": ";
            } else {
            os << endl << "Bus " << bus.first << ": ";
            }
            for (const string & stop : bus.second) {
                os << stop << " ";
            }
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        for (string stop : stops) {
            buses_with_stops[bus].push_back(stop);
            stops_with_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse answer;
        if (stops_with_buses.count(stop)!= 0) {
            for (const string& bus : stops_with_buses.at(stop)) {
                answer.buses.push_back(bus);
            }
        }
        return answer;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse answer;
        if (buses_with_stops.count(bus) == 0) return answer;
        for (const auto & stop : buses_with_stops.at(bus)) {
                answer.stops.push_back(stop);
            if (stops_with_buses.at(stop).size() == 1) {
                answer.route_stops[stop].push_back("no interchange");
            } else {
                for (const auto& other_bus : stops_with_buses.at(stop)) {
                    if (other_bus != bus)
                        answer.route_stops[stop].push_back(other_bus);
                }
            }
        }
        return answer;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse answer;
        for (const auto & bus : buses_with_stops) {
            for (const string& stop : bus.second) {
                answer.all_buses[bus.first].push_back(stop);
            }
        }
        return answer;
    }

    void Print_fucking_all () {
        cout << "BUSES:" << endl;
        for (auto item : buses_with_stops) {
            cout << item.first << ": ";
            for (auto s : item.second) {
                cout << s << " ";
            }
            cout << endl;
        }
        cout << "STOPS:" << endl;
        for (auto item : stops_with_buses) {
            cout << item.first << ": ";
            for (auto a : item.second) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
private:
    map <string, vector <string>> buses_with_stops;
    map <string, vector <string>> stops_with_buses;

};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;


    cin >> query_count;
    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
//        cout << " stops are ";
        //      for (auto x : q.stops)
        //        cout << x << " ";
        // cout << endl;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            //    bm.Print_fucking_all();
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }
    return 0;
}
