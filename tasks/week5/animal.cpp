/*
 * =====================================================================================
 *
 *       Filename:  animal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.05.2018 19:28:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Animal {
    public:
    Animal(const string&t) : Name(t) {
    }
    void Print() {
        cout << Name << endl;
    }

        const string Name;
};

class Dog: public Animal {
    public:
        Dog (const string &t) : Animal(t) {}
        void Bark() {
            cout << Name << " barks: woof!" << endl;
        }
        };
/*
int main() {

    Dog Bob("Bob");
    Bob.Bark();
}*/
