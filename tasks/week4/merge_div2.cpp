/************************************************************************************//**
 *  @file       merge.cpp
 *
 *  @brief      Brief descriptinon of merge.cpp 
 *
 *  @date       2018-04-29 16:55
 *
 ***************************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_begin == range_end || range_begin == (range_end - 1)) {
      return;
      }
vector <typename RandomIt::value_type> elements (range_begin, range_end);
auto med = begin(elements) + elements.size()/2;
MergeSort(begin(elements), med);
MergeSort(med, end(elements));
  merge (begin(elements), med, med, end(elements), range_begin);
};
/*
int main () {
  vector <int> v = {6,4,7,6,4,4,0,1};
  MergeSort (begin(v), end(v));
  for (int x : v) {
      cout << x << " ";
      }
  cout << endl;
  return 0;
}
*/

