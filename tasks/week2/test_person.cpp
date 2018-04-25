#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};



/*class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
      firstname[year] = first_name;
      name_years.insert(year);
  }
  void ChangeLastName(int year, const string& last_name) {
      lastname[year] = last_name;
      lname_years.insert(year);
  }
  string GetFullName(int year) { 
        if (lastname.size() == 0 && firstname.size() == 0) return "Incognito";
        int mark1 = 0;
        int mark2 = 0;
        for (auto a : lname_years) {
            if (a <= year) mark1 = a;
        }

        for (auto a : name_years) {
            if (a <= year) mark2 = a;
        }
        if (mark1 == 0 && mark2 == 0) 
            return "Incognito";
        if (mark1 == 0) 
            return firstname[mark2] + " with unknown last name";
        if (mark2 == 0) 
            return lastname[mark1] + " with unknown first name";
        return firstname[mark2]+" "+lastname[mark1];

        }

private:
  set <int> name_years;
  set <int> lname_years;
  map <int, string> firstname;
  map <int, string> lastname;
};
*/
void TestNothingKnown () {
    Person NoName;
    AssertEqual(NoName.GetFullName(12), "Incognito", "No data in input");
    NoName.ChangeFirstName(10, "Ten");
    NoName.ChangeLastName(12, "12");
    AssertEqual(NoName.GetFullName(8), "Incognito", "No data before thie year");
}

void TestOnlyName () {
    Person Named;
    Named.ChangeFirstName(10, "Ten");
    AssertEqual(Named.GetFullName(10), "Ten with unknown last name", "Only name known");
    AssertEqual(Named.GetFullName(12), "Ten with unknown last name", "Only name known, year after change");
}

void TestOnlyLName() {
    Person Named;
    Named.ChangeLastName(10, "10");
    AssertEqual(Named.GetFullName(10), "10 with unknown first name", "Only last name known");
    AssertEqual(Named.GetFullName(12), "10 with unknown first name", "Only last name known, year after change");
    AssertEqual(Named.GetFullName(2), "Incognito", "Only last name known, year before change");
}

void TestChanges () {
    Person One;
    One.ChangeLastName(10, "1");
    One.ChangeFirstName(10, "Ten");
    AssertEqual(One.GetFullName(10), "Ten 1", "In a yaer of changes");
    AssertEqual(One.GetFullName(12), "Ten 1", "After year of changes");
    One.ChangeLastName(12, "12");
    AssertEqual(One.GetFullName(12), "Ten 12", "After year of changes");
    One.ChangeFirstName(12, "Twelve");
    AssertEqual(One.GetFullName(12), "Twelve 12", "After year of changes");
    AssertEqual(One.GetFullName(11), "Ten 1", "Between changes");
    One.ChangeFirstName(8, "Eight");
    AssertEqual(One.GetFullName(8), "Eight with unknown last name", "No lastname in seeries of changes");
    One.ChangeLastName(6, "6");
    AssertEqual(One.GetFullName(6), "6 with unknown first name", "No name in series of changes");
}



int main() {
  TestRunner runner;
      runner.RunTest(TestNothingKnown, "NoName Test");
      runner.RunTest(TestOnlyName, "Name test");
      runner.RunTest(TestOnlyLName, "Last name test");
      runner.RunTest(TestChanges, "Changes test");
      // добавьте сюда свои тесты;
  return 0;
}
