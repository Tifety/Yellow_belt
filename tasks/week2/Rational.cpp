#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

int gcd (int a, int b) {
    while (b != 0) {
        int c = a % b;
        a =   b;
        b = c;
    }
    return a;
}

class Rational {
public:
    Rational() {
    num = 0;
    dem = 1;
        // Реализуйте конструктор по умолчанию
    }

    Rational(int numerator, int denominator) {
     if (numerator == 0 ) {
         num = 0;
         dem = 1;
     } else {
    int g = gcd (numerator, denominator);
    num = numerator / g;
    dem = denominator / g;
    if ((num < 0 && dem < 0) || (num > 0 && dem < 0)) {
    num *= -1;
    dem *= -1;
    }
    } // Реализуйте конструктор
//    cout << num << " " << dem << endl;
    }

    int Numerator() const {
     return num;        // Реализуйте этот метод
    }

    int Denominator() const {
       return dem;
    }

private:
    int num;
    int dem;
        // Добавьте поля
};

bool operator == (const Rational& lhs, const Rational& rhs) {
if (lhs.Numerator() != rhs.Numerator()) return false;
if (lhs.Denominator() != rhs.Denominator ()) return false;
return true;
}


Rational operator +(const Rational& lhs, const Rational& rhs) {
int n = 0;
int m = 0;
    if (lhs.Denominator() == rhs.Denominator()) {
n = lhs.Numerator() + rhs.Numerator();
m = lhs.Denominator();
} else {
n = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
m = lhs.Denominator() * rhs.Denominator();
}
return Rational (n, m);
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
int n = 0;
int m = 0;
    if (lhs.Denominator() == rhs.Denominator()) {
n = lhs.Numerator() - rhs.Numerator();
m = lhs.Denominator();
} else {
n = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
m = lhs.Denominator() * rhs.Denominator();
}
return Rational (n, m);
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
int n = 0;
int m = 0;
n = lhs.Numerator() * rhs.Numerator();
m = lhs.Denominator() * rhs.Denominator();
return Rational (n, m);
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
int n = 0;
int m = 0;
n = lhs.Numerator() * rhs.Denominator();
m = lhs.Denominator() * rhs.Numerator();
return Rational (n, m);
}

istream& operator >> (istream& stream, Rational& rational) {
    int n=0;
    int m=0;
    if (stream >> n) {
    stream.ignore(1);
    if (stream >> m) {
    rational = Rational(n, m);}
    }
    return stream;
}

ostream& operator << (ostream& stream, const Rational& rational) {
stream << rational.Numerator();
stream << "/";
stream << rational.Denominator();
return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
if (lhs.Numerator() * rhs.Denominator() < lhs.Denominator()*rhs.Numerator()) return true;
return false;
}

/* bool operator > (const Rational& lhs, const Rational& rhs) {
if (lhs.Numerator() * rhs.Denominator() > lhs.Denominator()*rhs.Numerator()) return true;
return true;
}*/


int main() {
        {
                    set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
                    if (rs.size() != 3) {
                                            cout << "Wrong amount of items in the set" << endl;
                                                        return 1;
                                                                }
         vector<Rational> v;
        for (auto x : rs) {
                        v.push_back(x);
                                }
                if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
                                cout << "Rationals comparison works incorrectly" << endl;
                                            return 2;
                }                                         
                }
 {
             map<Rational, int> count;
                     ++count[{1, 2}];
                             ++count[{1, 2}];

                                     ++count[{2, 3}];
if (count.size() != 2) {
                cout << "Wrong amount of items in the map" << endl;
                            return 3;
                                    }
 }

     cout << "OK" << endl;
         return 0;
}


