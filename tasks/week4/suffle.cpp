/************************************************************************************//**
 *  @file       suffle.cpp
 *
 *  @brief      Brief descriptinon of suffle.cpp 
 *
 *  @date       2018-04-29 12:41
 *
 ***************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

void print_v (vector <int>& s) {
 for (auto it = s.begin(); it != s.end(); it++) {
   cout << *it << " ";
 }
 cout << endl;
}

void shuffle_v (vector <int>& s) {
  vector <int> start = s;
  while (prev_permutation(s.begin(), s.end())) {
  print_v(s);
  }

}

int main () {
 int N;
 cin >> N;
 vector <int> shuffle(N);
iota(shuffle.rbegin(), shuffle.rend(), 1);
print_v(shuffle);
shuffle_v(shuffle);
}



