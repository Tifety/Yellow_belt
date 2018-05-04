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
  if ((range_end - range_begin) < 3) {
      return;
      }
vector <typename RandomIt::value_type> elements (range_begin, range_end);
auto med1 = begin(elements) + elements.size()/3;
auto med2 = med1 + elements.size()/3;
MergeSort(begin(elements), med1);
MergeSort(med1, med2);
MergeSort(med2, end(elements));
vector <typename RandomIt::value_type> tmp;
merge (begin(elements), med1, med1, med2, back_inserter(tmp));
merge (begin(tmp), end(tmp), med2, end(elements), range_begin);
};
/* /
int main () {
  vector <int> v = {6,4,7,6,4,4,0,1,5};
  MergeSort (begin(v), end(v));
  for (int x : v) {
      cout << x << " ";
      }
  cout << endl;
  return 0;
}
*/

