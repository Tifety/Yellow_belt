/************************************************************************************//**
 *  @file       person.cpp
 *
 *  @brief      Brief descriptinon of person.cpp 
 *
 *  @date       2018-04-29 14:51
 *
 ***************************************************************************************/

#pragma once

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;
  Gender gender;
  bool is_employed;
};


