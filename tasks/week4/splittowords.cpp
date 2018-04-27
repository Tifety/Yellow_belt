/*
 * =====================================================================================
 *
 *       Filename:  splittowords.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.04.2018 19:49:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <string> SplitIntoWords(const string& s) {
vector <string> answer = {"C", "Cpp", "Java", "Python"};
auto start = begin(s);
for (auto it = begin(s); it != end(s); it ++) {
auto new_end = s.find(" ");

}

return answer;
}

int main () {
    string s = "C Cpp Java Python";

    vector <string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;
return 0;
}
