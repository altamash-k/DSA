#include<bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 26;

void uncommonChars(string str1, string str2)
{
    int present[MAX_CHARS];
    for(int i = 0; i < MAX_CHARS; i++)
    {
        present[i] = 0;
    }

    int l1 = str1.length();
    int l2 = str2.length();

    for(int i = 0; i < l1; i++)
        present[str1[i] - 'a'] = 1;
    
    for(int i = 0; i < l2; i++)
    {
        if(present[str2[i] - 'a'] == 1 || present[str2[i] - 'a'] == -1)
            present[str2[i] - 'a'] = -1;
        else
            present[str2[i] - 'a'] = 2;
    }

    for(int i = 0; i < MAX_CHARS; i++)
    {
        if(present[i] == 1 || present[i] == 2)
            cout << (char (i +'a')) << " ";
    }
}

int main()
{
    string str1 = "characters";
    string str2 = "alphabets";
    uncommonChars(str1, str2);
    return 0;
}