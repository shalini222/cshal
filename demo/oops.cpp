#include <bits/stdc++.h>
using namespace std;

class student
{
    string name;

public:
    int age;
    bool gender;

    string s;
    void setName(string s)
    {
        name = s;
    }
    void getName()
    {
        cout << name << endl;
    }

    // default constructore

    student()
    {
        cout << "default cons" << endl;
    }

    //parameterised constructor

    student(string n, int a, bool g)
    {
        cout << "Parameterised Cons" << endl;
        name = n;
        age = a;
        gender = g;
    }
    // copied constructer

    student(student &a)
    {
        cout << " Copied cons" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    void printInfo()
    {
        cout << " name = ";
        cout << name << endl;
        cout << " age = ";
        cout << age << endl;
        cout << " gender = ";
        cout << gender << endl;
    }

    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
    //destructor

    ~student()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{

    // student arr[3];

    // for (int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cout << " Name =";
    //     cin >> s;
    //     arr[i].setName(s);
    //     cout << " age =";
    //     cin >> arr[i].age;
    //     cout << "gender =";
    //     cin >> arr[i].gender;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }

    student a("Shalini", 21, 0);
    a.printInfo();
    student b;
    student c = a;
    if (c == a)
    {
        cout << " Same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    return 0;
}