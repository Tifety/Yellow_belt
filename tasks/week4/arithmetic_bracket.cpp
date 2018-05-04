/************************************************************************************//**
 *  @file       arithmetic.cpp
 *
 *  @brief      Brief descriptinon of arithmetic.cpp 
 *
 *  @date       2018-05-01 10:44
 *
 ***************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

void add_operation(deque <string>& expr) {
char op;
int work;
cin >> op >> work;
//cout << op << " " << work << endl;
string po(1, op);
expr.push_front("(");
expr.push_back(")");
expr.push_back(" " + po + " ");
expr.push_back(to_string(work));
}

void deq_print(deque <string>& deq) {
  for (auto a: deq) {
    cout << a ;
  } 
 cout << endl; 
}

int main () 
{
deque <string> expr;
int start, work;
unsigned N;
char op;
cin >> start >> N;
expr.push_back(to_string(start));
for (int i = 0; i <N; i++) {
add_operation(expr);
}
deq_print(expr);

  return 0;

}
