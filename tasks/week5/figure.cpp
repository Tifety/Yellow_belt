/************************************************************************************//**
 *  @file       figure.cpp
 *
 *  @brief      Brief descriptinon of figure.cpp 
 *
 *  @date       2019-03-29 14:05
 *
 ***************************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip> 
using namespace std;

class Figure {
  public:
  virtual string Name  ( ) const = 0;
virtual double Perimeter () const = 0;
virtual double Area () const = 0;
};

class Triangle : public Figure {
 public:
  Triangle ( double a_, double b_, double c_) : 
             a(a_), b(b_), c(c_) {}
 string Name ()const   override{
 return type;
 }

 double Perimeter () const override {
   return a+b+c;
 }

 double Area () const override {
  double half_per = (a + b + c) / 2;
  return sqrt ( half_per * (half_per - a) * (half_per - b) * (half_per -c));
 }

  private:
    const string type = "TRIANGLE";
    const double a, b, c; 
};

class Rect : public Figure  {
  public: 
    Rect (double a_, double b_ ) : a(a_), b(b_) {}

    string Name () const override {
      return type;
    }

    double Perimeter () const override {
      return a*2 + b * 2;
    }

    double Area () const override {
      return a*b;
    }

  private:
      const string type = "RECT";
      const double a, b;
} ;

class Circle : public Figure {
  public:
  Circle (double r_) : r(r_) {}

  string Name () const override {
    return type;
  }

  double Perimeter() const override {
    return 3.14*r*2;
  }

  double Area () const override {
return 3.14*r*r;
  }

  private: 
  const string type = "CIRCLE";
  const double r;

};

shared_ptr <Figure>  CreateFigure (istringstream &is) {
string type;
is >> type;
if (type == "TRIANGLE") {
  double a, b, c;
  is >> a >> b >> c;
  return make_shared <Triangle> (a, b, c);
}
if (type == "RECT") {
  double a, b;
  is >> a >> b;
  return make_shared <Rect> (a, b);
}
double r;
is >> r;
return make_shared <Circle> (r);
}

/*int main () {

  vector <shared_ptr <Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);
    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back (CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& curr : figures) {
        cout << curr->Name() << " " << curr->Perimeter() << " " << curr->Area() << endl;
      }
    }
    else break;
    }
}
*/

