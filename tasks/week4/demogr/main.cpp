/*************************************************************************************//**
 *  @file       main.cpp
 *
 *  @brief      Main entry to C-based application  
 *
 *  @date       2018-04-29 15:06
 *         
 **************************************************************************************/

#include <vector>
#include <iostream>
#include "person.h"
#include "medage.cpp"
#include "status.h"

using namespace std;

/******** Function ************************************************//**
 *   @brief     main entry Function
 *
 *   @param     argc - number of parameters pass to the application from 
 *                 command line input (stdin)
 *   @param     argv - array of parameters pass to the application from 
 *                 command line input (stdin)
 *
 *   @return    exit code of the application
 *********************************************************************/

int main(int argc, const char **argv)
{
  vector <Person> persons = {
    {31, Gender::MALE, false},
    {40, Gender::FEMALE, true},
    {24, Gender::MALE, true},
    {20, Gender::FEMALE, true},
    {80, Gender::FEMALE, false},
    {78, Gender::MALE, false},
    {10, Gender::FEMALE, false},
    {55, Gender::MALE, true},
  };
  PrintStats(persons);

    return 0;
}


