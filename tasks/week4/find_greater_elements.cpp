/************************************************************************************//**
 *  @file       find_greater_elements.cpp
 *
 *  @brief      Brief descriptinon of find_greater_elements.cpp 
 *
 *  @date       2018-04-27 09:49
 *
 ***************************************************************************************/

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
vector <T> FindGreaterElements(const set <T>& elements, const T& border); 
template <typename T>
vector <T> FindGreaterElements(const set <T>& elements, const T& border) {
  vector <T> answer;
  auto bord = find_if (begin(elements), end(elements), 
      [border] (const T& el) {
        return el > border;
        }
      );
  for (auto i = bord; i != end(elements); i++){
   answer.push_back(*i);
  }
return answer;
}

/*  int main() {
for (int x : FindGreaterElements( set <int> {1,5,7,8}, 5)) {
cout << x << " ";
}
cout << endl;
}*/
