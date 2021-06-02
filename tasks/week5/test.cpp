/************************************************************************************//**
 *  @file       test.cpp
 *
 *  @brief      Brief descriptinon of test.cpp 
 *
 *  @date       2019-04-01 16:16
 *
 ***************************************************************************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human
{
public:
    Human(const string& profession, const string& name)
    : _prof(profession)
    , _name(name)
    {
    }

    const string& Prof() const
    {
        return _prof;
    }

    const string& Name() const
    {
        return _name;
    }

    virtual void Walk(const string& destination) const
    {
        cout << _prof << ": " << _name << " walks to: " << destination << endl;
    }

protected:
    const string _prof = "Human";
    const string _name = "Noname";
};

class Student : public Human
{
public:
    Student(const string& name, const string& favouriteSong)
    : Human("Student", name)
    , _song(favouriteSong)
    {
    }

    void Learn() const
    {
        cout << _prof << ": " << _name << " learns" << endl;
    }

    void Walk(const string& destination) const override
    {
        Human::Walk(destination);
        SingSong();
    }

    void SingSong() const
    {
        cout << _prof << ": " << _name << " sings a song: " << _song << endl;
    }

private:
    string _song;
};


class Teacher : public Human
{
public:

    Teacher(const string& name, const string& subject)
    : Human("Teacher", name)
    , _subj(subject)
    {
    }

    void Teach() const
    {
        cout << _prof << ": " << _name << " teaches: " << _subj << endl;
    }

public:
    string _subj;
};


class Policeman : public Human
{
public:
    Policeman(const string& name)
    : Human("Policeman", name)
    {
    }

    void Check(const Human& h) const
    {
        cout << _prof << ": " << _name << " checks " << h.Prof() << ". " << h.Prof() << "'s name is: " << h.Name() << endl;
    }
};


void VisitPlaces(const Human& h, const vector<string>& places)
{
    for (const auto& p : places)
    {
        h.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
