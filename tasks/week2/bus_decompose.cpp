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
//        for (int i = 0; i < stop_count; i++) {
//            string a;
//            is >> a;
//            q.stops.push_back(a);
 //       }
        for (string & st : q.stops) {
            cin >> st;
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
   cout << "IN5" << endl;
  if (r.buses.size()== 0) {
     os << "No stop" << endl;
  } else {
   cout << "IN6" << endl;
      for (const string & bus : r.buses) {
          os << bus << " ";
      }
  }
  return os;
}

struct StopsForBusResponse {

    // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
 map <string, vector <string>> all_buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.all_buses.size() == 0) {
      os << "No buses" << endl;
  } else {
    for (const auto& bus : r.all_buses) {
        os << "Bus " << bus.first << ": ";
        for (const string & stop : bus.second) {
            os << stop << " ";
        }
    cout << endl;
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
      // Реализуйте этот метод
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
   cout << "IN3" << endl;
    BusesForStopResponse answer;
  if (stops_with_buses.count(stop)!= 0) {
   cout << "IN4" << endl;
      for (const string& bus : stops_with_buses.at(stop)) {
          answer.buses.push_back(bus);
      }
  }
return answer;
 }

  //StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
 // }

 AllBusesResponse GetAllBuses() const {
    AllBusesResponse answer;
    for (const auto & bus : buses_with_stops) {
        for (const string& stop : bus.second) {
        answer.all_buses[bus.first].push_back(stop);
        }
    }
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
    cout << " stops are ";
    for (auto x : q.stops) 
        cout << x << " ";
    cout << endl;
    switch (q.type) {
    case QueryType::NewBus:
   cout << "IN1" << endl;
   bm.AddBus(q.bus, q.stops);
   cout << "OUT1" << endl;
   cout << "IN" << endl;
   bm.Print_fucking_all();
   cout << "OUT" << endl;
      break;
    case QueryType::BusesForStop:
   cout << "IN2" << endl;
   cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
   //   cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
 bm.GetAllBuses();
      //   cout << bm.GetAllBuses() << endl;
      break;
    }
  }
  return 0;
}
