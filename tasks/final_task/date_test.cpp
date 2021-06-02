#include "date.h"
#include "test_runner.h"


void TestParseDate() {
    istringstream is ("2000-12-1 some_more_data");
    Date date(2000, 12, 1);
    Date date_parse = ParseDate(is);
    AssertEqual(date.GetYear(), 2000, "parsing year in constructor");
    AssertEqual(date.GetMonth(), 12, "parsing month in constructor");
    AssertEqual(date.GetDay(), 1, "parsing day in constructor");
    AssertEqual(date_parse.GetYear(), 2000, "parsing year in function");
    AssertEqual(date_parse.GetMonth(), 12, "parsing month in function");
    AssertEqual(date_parse.GetDay(), 1, "parsing day in function");
}

void TestCoutDate () {
    vector <Date> dates_in = { Date(1999, 12, 30), Date(200, 1, 2),
                            Date (20, 12, 12), Date(2, 12, 12) };
    vector <string> dates_out = {"1999-12-30", "0200-01-02", "0020-12-12", "0002-12-12"};

    for (int i = 0; i < dates_in.size(); i++) {
        stringstream os;
        string s;
        os << dates_in[i];
        os >> s;
        string hint = "Output " + to_string(i);
        AssertEqual(s, dates_out[i], hint);
    }
}