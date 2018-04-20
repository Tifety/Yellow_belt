/*
 * =====================================================================================
 *
 *       Filename:  phone_number.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20.04.2018 19:39:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "phone_number.h"
#include <iostream>
PhoneNumber::PhoneNumber (const string & international_number) {
    try {
    if (international_number[0]!='+') throw "invalid_argument";
    int i=0;
    while (international_number[i]!='-') {
        PhoneNumber::country_code_+=international_number[i];
        i++;
    }
        i++;
        while (international_number[i]!='-' ) {
            PhoneNumber::city_code_+=international_number[i];
        i++;
        }
        i++;
    }

catch (const string& e) {
//    std::cout << e.what();
}
}


string PhoneNumber::GetCountryCode() const {
    return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const{
    return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return PhoneNumber::country_code_ + "-" +  PhoneNumber::city_code_ + "-" + PhoneNumber::local_number_;
}
