#pragma once
#include <string>
#include <iostream>
#include <iomanip>
//#include <sstream>
//#include <vector>
#include <tuple>

using namespace std;

class Date {
public:
    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

    Date (const int& y, const int& m, const int& d): year(y), month(m), day(d) {
    }

private:
    const int year;
    const int month;
    const int day;
};

Date ParseDate(std::istream& is);

ostream& operator << (ostream& stream, const Date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& left, const Date& right);

void TestParseDate();
void TestCoutDate();