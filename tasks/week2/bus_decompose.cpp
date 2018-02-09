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
        for (int i = 0; i < stop_count; i++) {
            string a;
            is >> a;
            q.stops.push_back(a);
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
string stop;
vector <string> buses_for_stop;
};

/*
ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
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
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  return os;
}
*/
class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
     for (string stop : stops) {
         buses_with_stops[bus].push_back(stop);
         stops_with_buses[stop].push_back(bus);
     }
      // Реализуйте этот метод
  }

 // BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
//  }

  //StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
 // }

 // AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
//  }

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
   //   cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
   //   cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
   //   cout << bm.GetAllBuses() << endl;
      break;
    }
  }
  return 0;
}
