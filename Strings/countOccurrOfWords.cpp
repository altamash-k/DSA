/*
    Count the occurrences of all the words in a string
    input: if it is to be, it is up to me
    output: if 1, it 2, is 2, to 2, be 1, up 1, me 1
*/

#include<bits/stdc++.h>
using namespace std;

void countWords(string str)
{
    map<string, int> mp;
    string words = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            if(mp.find(words) == mp.end())
            {
                mp.insert(make_pair(words, 1));
                words = "";
            }
            else
            {
                mp[words]++;
                words = "";
            }
        }
        else
            words += str[i];
    }

    if(mp.find(words) == mp.end())
    {
        mp.insert(make_pair(words, 1));
    }
    else
    {
        mp[words]++;
    }

    for(auto& it:mp)
        cout << it.first << " " << it.second << endl;
}

int main()
{
    string str;
    getline(cin, str);

    cout << str.size();

    countWords(str);

    return 0;
}