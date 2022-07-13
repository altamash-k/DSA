/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"

    Sliding window, expand if unique, contract if duplicate

    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int longestSubStr(string s)
{
    unordered_set<char> letters;
    int i = 0;
    int j = 0;

    int res = 0;

    while(j < s.size())
    {
        if(letters.find(s[j]) == letters.end())
        {
            letters.insert(s[j]);
            res = max(res, j-i+1);
            j++;
        }
        else
        {
            letters.erase(s[i]);
            i++;
        }
    }

    return res;

}

int main()
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    cout << "Length of longest substr without repeating: " << longestSubStr(s);
}
