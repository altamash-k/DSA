#include<bits/stdc++.h>
using namespace std;

char firstRepeatingChar(string &str)
{
    unordered_set<char> h;
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if(h.find(c) != h.end())
            return c;
        else
            h.insert(c);
    }

    return '\0';
}

int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    cout << firstRepeatingChar(str);
}