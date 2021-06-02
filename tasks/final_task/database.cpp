#include "database.h"

    void Database::Add(const Date& date, const string& event) {
        if (base_uniq.insert({date, event}).second) {
      //  if (base[date].empty()
    //   || find(base[date].begin(), base[date].end(), event) == base[date].end()) {
            base[date].push_back(event);
            count ++;
        }
    }


     int Database::RemoveIf(const std::function<bool(Date, string)>& predicate) {
         int deleted_count = 0;
         for (auto i = base_uniq.begin(); i != base_uniq.end();) {
                if (predicate(i->first, i->second)) i = base_uniq.erase(i);
                else ++i;
         }
         vector <Date> to_del;
        for (auto&  b : base) {
             auto new_end=stable_partition(b.second.begin(), b.second.end(), [=](const string& s) {
                 return !predicate(b.first, s);
             });
             deleted_count+= b.second.end() - new_end;
             b.second.erase(new_end, b.second.end());
             if (b.second.empty()) to_del.push_back(b.first);
         }
         for (auto d : to_del) {
             base.erase(d);
         }
     return deleted_count;
     }
      vector <string> Database::FindIf(const std::function<bool(Date, string)>& predicate)const {
        vector <string> found;
        for (const auto& b : base) {
            for (const auto& event : b.second){
                if (predicate(b.first, event)) {
                   found.push_back(BaseToString(b.first, event));
                }
            }
        }
        return found;
    }

    void Database::Print(ostream& stream) const {
        for (const auto& d : base) {
            for (const auto& s : d.second) {
                stream << BaseToString(d.first, s) << endl;
            }
        }
    }

    string Database::Last(const Date date) const {
        auto it = base.upper_bound(date);
        stringstream s;
        string result;
        if (it == base.begin()) {
            throw invalid_argument("No entries");
        }
        it--;
        return BaseToString(it->first, it->second.back());
    }

string BaseToString(const Date& date,const string& event)  {
    stringstream st;
    string out;
    st << date << " " << event << endl;
    getline(st, out);
    return out;
}