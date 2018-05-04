/************************************************************************************//**
 *  @file       find_near.cpp
 *
 *  @brief      Brief descriptinon of find_near.cpp 
 *
 *  @date       2018-04-29 19:02
 *
 ***************************************************************************************/

#include <iostream>
#include <set>
#include <utility>
using namespace std;

set <int>::const_iterator FindNearestElement(
    const set<int>& numbers, int border) {
    if (numbers.size() == 0) return end(numbers);
    auto range = numbers.equal_range (border); 
    if (range.first != range.second) return range.first;
    if (range.first == begin(numbers)) return range.first;
    if (range.first == end(numbers)) return prev(range.first);
    if ((border - *(prev(range.first))) <= (*range.second - border)) 
      return prev(range.first);
    return range.second;
}
/* 
int main() {
  set <int> num = {1, 4, 6};

  cout << *FindNearesElements(num, 0) << " " <<
*FindNearesElements(num, 3) << " " <<
*FindNearesElements(num, 5) << " " <<
*FindNearesElements(num, 6) << " " <<
*FindNearesElements(num, 100) << endl;
set <int> empty;
cout << (FindNearesElements(empty, 8) == end(empty)) << endl;
return 0;
}
*/

