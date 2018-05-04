/************************************************************************************//**
 *  @file       remove.cpp
 *
 *  @brief      Brief descriptinon of remove.cpp 
 *
 *  @date       2018-04-29 12:06
 *
 ***************************************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
void RemoveDuplicates(vector <T>& elements) {
  sort (begin(elements), end(elements));
  auto it = unique(begin(elements) , end(elements));
  elements.erase(it, end(elements));
}



