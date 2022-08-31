#include<bits/stdc++.h>
using namespace std;

void moveHash(string &str)
{
    char str1[100], str2[100];
    int j = 0, k = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '#')
            str1[j++] = str[i];
        else
            str2[k++] = str[i];
    }

    strcat(str1, str2);
    cout << str1;
}

int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    moveHash(str);
}