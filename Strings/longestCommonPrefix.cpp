#include<bits/stdc++.h>
using namespace std;

string commonPrefixUtil(string str1, string str2)
{
    string res;
    int minlen = min(str1.length(), str2.length());
    for(int i = 0; i < minlen; i++)
    {
        if(str1[i] != str2[i])
            break;
        res += str1[i];
    }
    return (res);
}

string commonPrefix(string arr[], int n)
{
    string prefix = arr[0];
    for(int i = 0; i < n; i++)
    {
        prefix = commonPrefixUtil(prefix, arr[i]);
    }
    return (prefix);
}

int main()
{
    string arr[] = {"altamash", "altam",
                    "alta", "alto"};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    string ans = commonPrefix(arr, n);
 
    if (ans.length())
        printf ("The longest common prefix is - %s",
                 ans.c_str());
    else
        printf("There is no common prefix");
 
    return (0);
}