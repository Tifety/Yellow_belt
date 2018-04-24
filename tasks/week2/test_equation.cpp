#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c);
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

void TestWrongNumber () {
    double a, b,c;
    for (int i = 0; i <20; i++) {
        a = rand()%100 - 50;
        b = rand()%100 - 50;
        c = rand()%100 - 50;
        int answer = GetDistinctRealRootCount(a, b, c);
        bool in_space = true;
        if (answer > 3 || answer < 0) in_space = false;
        Assert(in_space, "Wrong number of roots");
    }
}

void TestNoRoot () {
    AssertEqual (GetDistinctRealRootCount(2, 6, 9), 0 , "If a=2, b=6, c=9 there is no root");
    AssertEqual (GetDistinctRealRootCount(4, 0, 1),0, "If b=0 and c > 0  there is no root");
   AssertEqual (GetDistinctRealRootCount(0, 0, 4),0, "If a==0, b==0 there is always no root" );
}

void TestOneRoot () {
    AssertEqual(GetDistinctRealRootCount(1, 4, 4), 1, "If a=1, b=4, c=4 there is one root");
    AssertEqual(GetDistinctRealRootCount(0, 1, 3), 1, "If a=0 there is always 1 root");
}

void TestTwoRoot () {
    AssertEqual (GetDistinctRealRootCount(4, 0, -1),2, "If b=0 and c < 0  there is two roots");
    AssertEqual(GetDistinctRealRootCount(5, 6, -7), 2, "If a=5, b=6, c=-7 there are two roots");
    AssertEqual(GetDistinctRealRootCount(4, 6, 0), 2, "If a=4, b=6, c=0 there are two roots");
}


int GetDistinctRealRootCount(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (a == 0) {
        if (b == 0) return 0;
        if (b != 0) return 1;
    }
    if (D == 0) return 1;
    if (D > 0) return 2;
    if (D < 0) return 0;
    // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}

int main() {
  TestRunner runner;
  runner.RunTest(TestNoRoot, "TestNoRoot");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestTwoRoot, "TestTwoRoot");
  runner.RunTest(TestWrongNumber, "TestWrongNumber");
  cout << GetDistinctRealRootCount(1, 0 , 0) << endl;
  
  // добавьте сюда свои тесты
  return 0;
}
