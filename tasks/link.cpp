/*
 * =====================================================================================
 *
 *       Filename:  link.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19.01.2018 20:09:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <map>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

template <typename Key, typename Value> Value& GetRefStrict (map <Key, Value>& m, Key i);

template <typename Key, typename Value> 
Value& GetRefStrict (map  <Key, Value>& m, Key i) {
    if (m.count(i)) return (m.at(i));
    else throw runtime_error("");
}


int main () {
map <int, string> m = {{0, "value"}};
map <int, int> k = {{0, 1}};
int & a = GetRefStrict(k, 1);
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl;
}
