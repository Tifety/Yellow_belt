/************************************************************************************//**
 *  @file       find_start.cpp
 *
 *  @brief      Brief descriptinon of find_start.cpp 
 *
 *  @date       2018-04-29 21:25
 *
 ***************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


bool compare_first(const string& s, const char c) {
  return s[0] < c;
}
bool compare_second(const char c, const string& s) {
  return s[0] > c;
}
template <typename RandomIt>
pair <RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char  prefix) {
    auto start = range_begin;
  auto finish = range_end;  
/*  if ((*range_begin)[0] > prefix) {
     return make_pair(range_begin, range_begin);
  } 
  if ((*prev(range_end))[0] < prefix) {
    return make_pair(range_end, range_end);
  }*/
  start = lower_bound (range_begin, range_end, prefix, compare_first);
  finish = upper_bound(range_begin, range_end, prefix, compare_second);
  return make_pair(start, finish);
}

 
int main() {
  const vector <string> sorted_strings = {"moscow", "murmansk", "vologda"};
  const auto res = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = res.first; it!=res.second; it++) {
    cout << *it << " ";
  }
  cout << endl;

  const auto a_res = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'a');
  for (auto it = a_res.first; it!=a_res.second; it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << (a_res.first - begin(sorted_strings)) << " " <<
    (a_res.second - begin(sorted_strings)) << endl;
  const auto p_res = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'n');
  cout << (p_res.first - begin(sorted_strings)) << " " <<
    (p_res.second - begin(sorted_strings)) << endl;
  const auto z_res = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_res.first - begin(sorted_strings)) << " " <<
    (z_res.second - begin(sorted_strings)) << endl;
}

