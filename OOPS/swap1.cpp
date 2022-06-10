#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int age;
    string name;
    void saysHi()
    {
        cout << name + " " << age << " Says Hi" << endl;
    }
};

void swap(Person psn1, Person psn2)
{
    Person tmp = psn1;
    psn1 = psn2;
    psn2 = tmp;
}

int main()
{
    Person p1;
    p1.age = 10;
    p1.name = "A";
    p1.saysHi();

    Person p2;
    p2.age = 20;
    p2.name = "B";
    p2.saysHi();

    swap(p1, p2);
    p1.saysHi();
    p2.saysHi();

    return 0;
}