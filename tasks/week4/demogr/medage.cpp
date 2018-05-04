/************************************************************************************//**
 *  @file       medage.cpp
 *
 *  @brief      Brief descriptinon of medage.cpp 
 *
 *  @date       2018-04-29 15:41
 *
 ***************************************************************************************/

#include "medage.h"


/************************************************************************************//**
 *  @file       medage.cpp
 *
 *  @brief      Brief descriptinon of medage.cpp 
 *
 *  @date       2018-04-29 14:53
 *
 ***************************************************************************************/

#include "person.h"
#include "medage.h"
using namespace std;

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector <typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size()/2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [] (const Person& lhs, const Person& rhs) {
      return lhs.age < rhs.age;
      }
      );
  return middle->age;
};



