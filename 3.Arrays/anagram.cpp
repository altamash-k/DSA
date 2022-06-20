#include<bits/stdc++.h>
using namespace std;

bool areAnagram(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    if(n1 != n2)
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i = 0; i<n1; i++)
    {
        if(s[i] != t[i])
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cout << "Enter s: ";
    cin >> s;

    cout << "Enter t: ";
    cin >> t;


    if(areAnagram(s, t))
        cout << "\nStrings are an anagram";
    else
        cout << "\nStrings are not an anagram";

    return 0;
}