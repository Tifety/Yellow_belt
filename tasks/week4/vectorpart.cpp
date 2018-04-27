/************************************************************************************//**
 *  @file       vectorpart.cpp
 *
 *  @brief      Brief descriptinon of vectorpart.cpp 
 *
 *  @date       2018-04-27 09:32
 *
 ***************************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void PrintVectorPart(const vector <int>& numbers) {
  auto res = find_if(begin(numbers), end(numbers), 
      [](const int& num) {
      return num < 0;});
  while (res!=begin(numbers)) {
  res--;
  cout << *res << " ";
  }
  cout << endl;

}
/*
int main() {
PrintVectorPart({6, 1, 8, -5, 4});
PrintVectorPart({-6,1,8,-5,4});
PrintVectorPart({6,1,8,4,5});
return 0;
}
*/
