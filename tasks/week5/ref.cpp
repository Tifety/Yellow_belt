#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person (const string& name, const string& t = "Person") : Name(name), type(t) {}
    virtual void Walk (string const & destination) const {
        cout << GetInfo() << " walks to: " << destination << endl;
    }

    string GetName() const {
        return Name;
    }

    string GetType() const {
        return type;
    }

    string GetInfo() const {
        return type+ ": " + Name;
    }

private:
    const string Name;
    const string type ;
};


class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong): Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << GetInfo()  << " learns" << endl;
    }

    void Walk(const string &  destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << GetInfo() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject)  {}

    void Teach() const {
        cout << GetInfo()  << " teaches: " << Subject << endl;
    }
private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string & name) : Person(name, "Policeman") {}

    void Check(Person const & p) {
        cout << GetInfo() << " checks " << p.GetType() << ". "
             << p.GetType() << "'s name is: " << p.GetName() << endl;
    }

};


void VisitPlaces (Person const & person, vector <string> const places) {
    for (auto const & p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    p.Check(s);
    p.Check(t);
    p.Check(p);
    VisitPlaces(t, {"Moscow", "London"});
    VisitPlaces(s, {"Moscow", "London"});
    VisitPlaces(p, {"Moscow"});
    t.Teach();
    s.Learn();
    s.SingSong();
    return 0;
}
