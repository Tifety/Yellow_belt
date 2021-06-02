#include "date.h"

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& is)  {
    int year;
    int month;
    int day;
    string err = "Wrong date format";
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    Date d(year, month, day);
    return d;
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') <<  date.GetYear() << setw(1) << "-"
           << setw(2) << setfill('0') <<date.GetMonth() << setw(1) << "-"
           << setw(2) << setfill('0') << date.GetDay() ;
    return stream;
}
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& left, const Date& right) {
    auto l_key = make_tuple(left.GetYear(), left.GetMonth(), left.GetDay());
    auto r_key = make_tuple(right.GetYear(), right.GetMonth(), right.GetDay());
    return l_key==r_key;
}