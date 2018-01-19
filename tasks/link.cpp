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

using namespace std;

template <typename Key, typename Value> Value& GetRefStrict (map <Key, Value> m, Key i);

template <typename Key, typename Value> 
Value&GetRefSrtict (map  <Key, Value> m, Key i) {
Value& answer = &m[i];
    return answer;
}

int main () {
map <int, string> m = {{0, "value"}};
string& item = GetRefStrict(m, 0);
item = "newvalue";
cout << m[0] << endl;
}
