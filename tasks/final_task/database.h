#pragma once
#include "date.h"

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <functional>

string BaseToString(const Date& date,const string& event);

class Database {
public:

    void Add(const Date& date, const string& event);

         int RemoveIf(const std::function<bool(Date, string)>& predicate);

      vector <string> FindIf(const std::function<bool(Date, string)>& predicate) const;

    void Print(ostream& stream) const;

    string Last(Date date) const;

private:
    map <Date, vector <string>> base;
    set <pair<Date, string>> base_uniq;
    int count=0;

};

void FillTestbase (Database& db);
void TestAddPrint();
void TestLast();
void TestFindIf();
void TestRemoveIf() ;
