/*
 * =====================================================================================
 *
 *       Filename:  sqr.cpp
 *
 *    Description: Yandex "Yellow belt" task. Need to write a  template sqrt function for  containers.
 *
 *        Version:  1.0
 *        Created:  19.01.2018 18:38:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;
template <typename T> T Sqr(T x);

template <typename First, typename Second>
pair <First, Second> operator * (const pair <First, Second>& x1, const pair <First, Second> x2);


template <typename Key, typename Value>
map <Key, Value> operator* (map <Key, Value> m1, map <Key, Value> m2);

template <typename Item>
vector <Item> operator * (const vector <Item>& v1, const vector <Item>& v2);

template <typename Item>
vector <Item> operator * (const vector <Item>& v1, const vector <Item>& v2) {
    int size = max (v1.size(), v2.size());
    vector <Item> answer(size);
    for  (int i = 0; i < size; i ++) {
        answer[i]=v1[i]*v2[i];
    }
    return answer;
}

template <typename Key, typename Value>
map <Key, Value> operator* (map <Key, Value> m1, map <Key, Value> m2) {}

template <typename First, typename Second>
pair <First, Second> operator * (const pair <First, Second>& x1, const pair <First, Second> x2) {
    pair <First, Second> ans;
    ans.first = x1.first * x2.first;
    ans.second = x1.second * x2.second;
    return ans;
}




template <typename T>
T Sqr( T x) {
    return x * x;
}

int main () {
    vector <int> a = {1,2,3,4,5,6};
    vector <int> b  = Sqr(a);
    cout << "One" << endl;
    cout << "Two" << endl;
    for (auto item : b) {
        cout << item << " " << endl;
    }
}
