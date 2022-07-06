#include<bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string &str)
{
    int n = str.length();
    int i = 1;
    int lps[n];
    lps[0] = 0;
    int len = 0;

    while(i < n)
    {
        if(str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int res = lps[n-1];
    return (res > n/2) ? res/2 : res;
}

int main()
{
    string s = "aabcdaabc";
    cout << longestPrefixSuffix(s);
    return 0;
}