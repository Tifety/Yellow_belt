/************************************************************************************//**
 *  @file       status.cpp
 *
 *  @brief      Brief descriptinon of status.cpp 
 *
 *  @date       2018-04-29 15:15
 *
 ***************************************************************************************/

#include "status.h"
#include <iostream>
#include "medage.cpp"
using namespace std;

void PrintStats (vector <Person> persons) {

cout <<"Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
auto count = partition (begin(persons), end(persons), 
    [] (const Person& per) {return per.gender ==Gender::FEMALE;});
cout <<"Median age for females = " << ComputeMedianAge(begin(persons), count)<< endl;
count = partition (begin(persons), end(persons), 
    [] (const Person& per) {return per.gender ==Gender::MALE;});
cout <<"Median age for males = " << ComputeMedianAge(begin(persons), count)<< endl;

count = partition (begin(persons), end(persons), 
    [] (const Person& per) {
    return per.gender ==Gender::FEMALE && per.is_employed == true;});
cout <<"Median age for employed females = "
     <<  ComputeMedianAge(begin(persons), count)<< endl;
count = partition (begin(persons), end(persons), 
    [] (const Person& per) {
    return per.gender ==Gender::FEMALE && per.is_employed == false;});
cout <<"Median age for unemployed females = " 
     <<  ComputeMedianAge(begin(persons), count)<< endl;
count = partition (begin(persons), end(persons), 
    [] (const Person& per) {
    return per.gender ==Gender::MALE && per.is_employed == true;});
cout <<"Median age for employed males = " 
     <<  ComputeMedianAge(begin(persons), count)<< endl;
count = partition (begin(persons), end(persons), 
    [] (const Person& per) {
    return per.gender ==Gender::MALE && per.is_employed == false;});
cout <<"Median age for unemployed males = " 
     <<  ComputeMedianAge(begin(persons), count)<< endl;

}


