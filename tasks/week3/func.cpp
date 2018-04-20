/*
 * =====================================================================================
 *
 *       Filename:  func.cpp
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  20.04.2018 16:23:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "sum_reverse_sort.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
/* void Print(vector <int> p) {
    for (int x : p) 
        cout << x << " ";
    cout << endl;
}
*/
int Sum (int x, int y) {
    return x + y;
}

string Reverse (string s) {
    string rev;
    for (int i = s.size() -1; i >=0 ; i--) {
        rev+=s[i];
    }
    return rev;
}

void Sort(vector <int>& nums) {
 sort (nums.begin(), nums.end());
    /*    for (int i= 0; i < nums.size()-1; i++) {
       int mi = nums[i]; 
       int mark = i;
       for (int j = i + 1; j  < nums.size(); j++) {
           if (mi > nums[j]) {
               mi = nums[j];
               mark = j;
           }
       }
       nums[mark] = nums[i];
       nums[i] = mi;
    //   Print (nums);
    }
 
    for (int i = 0; i < nums.size()-1; i++) {
    for (int j = i+1; j < nums.size(); j++) {
        if (mi > nums[j]) {
            int work = nums[i];
            nums[i]=nums[j];
            nums[j]=work;

        }
        }
    }
    */
}

  /*  
int main () {

    vector <int> test = {2,3,4,5,6,1,2,3,5,1};
    Sort(test);
    Print(test);
} */
