#include<bits/stdc++.h>
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

int main()
{
    Person p1;
    p1.age = 10;
    p1.name = "Abc";
    p1.saysHi();

    Person p2;
    p2.age = 20;
    p2.name = "Xyz";
    p2.saysHi();

    Person p3 = p1;
    p3.age = 30;
    p3.saysHi();
    p1.saysHi();
    
    return 0;
}