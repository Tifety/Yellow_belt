/************************************************************************************//**
 *  @file       split.cpp
 *
 *  @brief      Brief descriptinon of split.cpp 
 *
 *  @date       2018-04-27 22:31
 *
 ***************************************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector <string> SplitIntoWords( const string& s) {
vector <string> answer;
auto mark = begin(s);
while (mark != end(s)) {
  auto space = find (mark, end(s), ' ');
 // cout << *space << endl;
  string tmp="";
  for (auto it = mark; it < space; it ++) {
   tmp+=*it;
  }
  answer.push_back(tmp);
  if (space == end(s)) return answer;
  mark = space+1;
}
return answer;
}

/*  
int main() {
  string s = "C Cpp Java Python";
  vector <string> words = SplitInfoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
        cout <<"/";
        }
        cout << *it;
  }
  cout << endl;
  return 0;
}*/

