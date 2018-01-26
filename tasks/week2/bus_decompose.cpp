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
    if (operation == "NEW_BUS") q.type=QueryType::NewBus;
    if (operation == "BUSES_FOR_STOP") q.type = QueryType::BusesForStop;
    if (operation == "STOPS_FOR_BUS") q.type = QueryType::StopsForBus;
    if (operation == "ALL BUSES") q.type = QueryType::AllBuses;
    is  >> q.bus >> q.stop;
    for (int i = 0; i < q.stops.size(); i ++) {
        string a;
        is >> a;
        q.stops.push_back(a);
    }
    // Реализуйте эту функцию
  return is;
}
/*  
struct BusesForStopResponse {
  // Наполните полями эту структуру
};

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

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
  }
};

// Не меняя тела функции main, реализуйте функции и классы выше
*/
int main() {
  int query_count;
  Query q;

  cin >> query_count;
    cin >> q;
switch (q.type) {
    case QueryType::NewBus:
        cout << "New Bus" << endl;
        break;
    case QueryType::BusesForStop:
        cout << "Bus" << endl;
        break;
    case QueryType::StopsForBus:
        cout << "Stops" << endl;
        break;
    case QueryType::AllBuses:
        cout << "All" << endl;
        break;
}
    cout << q.bus << endl;
cout << q.stop << endl;
for (auto i : q.stops) {
    cout << i << " ";
}
cout << endl;
/* BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
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
*/
  return 0;
}
