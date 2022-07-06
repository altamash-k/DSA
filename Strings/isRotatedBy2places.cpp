#include<bits/stdc++.h>
using namespace std;

bool isRotated(string s1, string s2)\
{
    string clock_rot = "";
    string anticlock_rot = "";
    int len = s2.length();

    if(s1.length() != s2.length())
        return false;

    if(s1.length() < 2)
        return s1.compare(s2) == 0;

    anticlock_rot += s2.substr(len-2, 2) + s2.substr(0, len-2);
    clock_rot += s2.substr(2) + s2.substr(0, 2);

    return s1.compare(anticlock_rot) == 0 || s1.compare(clock_rot) == 0;
}

int main()
{
    string str1 = "amazon";
    string str2 = "azanam";
 
    isRotated(str1, str2) ? cout << "Yes": cout << "No";
    return 0;
}