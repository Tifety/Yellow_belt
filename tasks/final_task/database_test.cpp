#include "database.h"
#include "test_runner.h"
#include "condition_parser.h"

void FillTestbase (Database& db) {
    vector <string> answers;
    vector <pair<Date, string>> input= {
            {Date(1999, 3,12), "first event"},
            {Date(20,1,30), "second event"},
            {Date(1999, 2, 12), "third event"},
            {Date(20,1,30), "fourth event"}};
    for (const auto& x : input) {
        db.Add(x.first, x.second);
    }
}

void TestRemoveIf() {
     Database db;
    FillTestbase(db);
    vector <string> conditions = {
            "date == 2017-11-18", // no date
            "date == 1999-3-12" , // date one event
            "date == 20-1-30", // one date multipl.events
            "date == 20-1-30 AND event == \"first event\"",  //date and event search
            "date ==3-4-12 OR event == \"second event\"" //date or event search
    };

}


void TestFindIf() {
    Database db;
    FillTestbase(db);
    vector <string> conditions = {
            "date == 2017-11-18", // no date
            "date == 1999-3-12" , // date one event
            "date == 20-1-30", // one date multipl.events
            "date == 20-1-30 AND event == \"first event\"",  //date and event search
            "date ==3-4-12 OR event == \"second event\"" //date or event search
            };
    vector <vector <string>> answers = {
            {}, //no date
            {"1999-03-12 first event"},
            {"0020-01-30 second event", "0020-01-30 fourth event"},
            {},
            {"0020-01-30 second event"}
                };
    for (int i = 0; i < conditions.size(); i++) {
        istringstream is(conditions[i]);
        auto condition = ParseCondition(is);
        auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
        };
        AssertEqual(db.FindIf(predicate), answers[i], "condition"+to_string(i));
    }
}

void TestAddPrint () {
    Database db;
    string out;
    stringstream s;
    vector <string> answers = {"0020-01-30 second event",
                               "0020-01-30 fourth event",
                               "1999-02-12 third event",
                               "1999-03-12 first event"};
    vector <string> outs;
    FillTestbase(db);
    db.Add(Date(1999, 3,12), "first event");
    db.Print(s);
    for (string line; getline(s, line); ) {
        outs.push_back(line);
    }

    for (int i=0; i <outs.size(); i++) {
        AssertEqual(outs[i], answers[i], "Wrong adding");
    }

}
void TestLast() {
Database db;
FillTestbase(db);
AssertEqual(db.Last(Date(2000, 0, 0)), "1999-03-12 first event", "Later then all");
AssertEqual(db.Last(Date(1999, 2,12)), "1999-02-12 third event", "Date ist equal");
AssertEqual(db.Last(Date(20, 1, 30)), "0020-01-30 fourth event", "Several events in date");
AssertEqual(db.Last(Date(1999, 2, 24)), "1999-02-12 third event", "Date ist bigger");
}

