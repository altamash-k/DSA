#include<bits/stdc++.h>
using namespace std;

bool isMatched(string text, string pattern)
{
    int i = 0, j = 0;
    int n = text.size();
    int m = pattern.size();

    while(j < m && i < n)
    {
        if(pattern[j] != text[i])
        {
            i++;
            j = 0;
        }
        else if(pattern[j] == text[i])
        {
            i++;
            j++;
        }
    }

    if(j == m)
        return true;
    else
        return false;
}

int main()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    // cout << "Text Size: " << text.size(); 

    string pattern;
    cout << "Enter pattern: ";
    getline(cin, pattern);
    // cout << "pattern Size: " << pattern.size();

    if(isMatched(text, pattern) == true)
        cout << "true";
    else
        cout << "false";
}