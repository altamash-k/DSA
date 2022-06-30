#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<char> res;
    vector<char> hash;
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == '#')
        {
            hash.push_back(ch);
            continue;
        }
        res.push_back(ch);
    }

    for(int i = 0; i < hash.size(); i++)
    {
        res.push_back(hash[i]);
    }
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}