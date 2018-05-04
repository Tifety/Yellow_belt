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

struct Expression {
  deque <string> expr;
  string last_op="";
};

bool prior (const string& last, const string& work) {
if ((last == "-" || last == "+") && 
    (work=="*" || work == "/")) return true;
return false;
}

void add_operation(Expression& input) {
char op;
int work;
cin >> op >> work;
//cout << op << " " << work << endl;
string po(1, op);
if (prior(input.last_op, po)){
input.expr.push_front("(");
input.expr.push_back(")");
}
input.expr.push_back(" " + po + " ");
input.expr.push_back(to_string(work));
input.last_op = po;
}

void deq_print(deque <string>& deq) {
  for (auto a: deq) {
    cout << a ;
  } 
 cout << endl; 
}

int main () 
{
Expression arithm_expr;
int start, work;
unsigned N;
char op;
cin >> start >> N;
arithm_expr.expr.push_back(to_string(start));
for (int i = 0; i <N; i++) {
add_operation(arithm_expr);
}
deq_print(arithm_expr.expr);

  return 0;

}
