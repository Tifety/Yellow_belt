/************************************************************************************//**
 *  @file       person_with_binary_search.cpp
 *
 *  @brief      Brief descriptinon of person_with_binary_search.cpp 
 *
 *  @date       2018-04-29 20:23
 *
 ***************************************************************************************/


#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
      firstname[year] = first_name;
      name_years.insert(year);
  }
  void ChangeLastName(int year, const string& last_name) {
      lastname[year] = last_name;
      lname_years.insert(year);
  }

  
  
  map <int, string> :: iterator FindYear( map <int, string>& names, int& year) {
  auto res = names.upper_bound(year);
//  if (res == begin(names)) return res; 
  return res;
  }

  string GetFullName(int year) {
   auto fnames = FindYear(firstname, year); 
   auto lnames = FindYear(lastname, year);
  if (fnames == begin(firstname) && lnames == begin(lastname)) 
      return "Incognito";
  
  if (fnames == begin(firstname)) 
     return (*prev(lnames)).second + " with unknown first name";
  if (lnames == begin(lastname)) 
    return (*prev(fnames)).second + " with unknown last name"; 
  
  return (*prev(fnames)).second + " " + (*prev(lnames)).second;
   // cout << (*FindYear(lastname, year)).second << endl;
// cout << (*FindYear(firstname, year)).second << endl;
    /* 
        if (lastname.size() == 0 && firstname.size() == 0) return "Incognito";
        int mark1 = 0;
        int mark2 = 0;
        for (auto a : lname_years) {
            if (a <= year) mark1 = a;
        }

        for (auto a : name_years) {
            if (a <= year) mark2 = a;
        }
        if (mark1 == 0 && mark2 == 0) 
            return "Incognito";
        if (mark1 == 0) 
            return firstname[mark2] + " with unknown last name";
        if (mark2 == 0) 
            return lastname[mark1] + " with unknown first name";
        return firstname[mark2]+" "+lastname[mark1];
        */
  }

private:
  set <int> name_years;
  set <int> lname_years;
  map <int, string> firstname;
  map <int, string> lastname;
};
/*
int main() {
  Person person;
  person.ChangeFirstName(1965, "Pol");
  person.ChangeLastName(1967, "Serg");
  for (int year : {1900, 1965, 1967}) {
    cout << person.GetFullName(year) << endl;
  }
 person.ChangeFirstName(1970, "Apo");
 for (int year : {1969, 1970}) {
   cout << person.GetFullName(year) << endl;
 }

  person.ChangeLastName(1968, "Volk");
  for (int year : {1969,1970}) {
    cout << person.GetFullName(year) << endl;
  }
return 0;
}
*/
