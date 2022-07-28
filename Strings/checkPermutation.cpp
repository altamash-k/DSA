/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

bool areEqual(vector<int> a, vector<int> b)
{
    for(int i = 0; i < 26; i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

bool checkPermutation(string s1, string s2)
{
    if(s2.size() < s1.size())
        return false;
    vector<int> freqS1(26, 0);
    vector<int> freqS2(26, 0);
    for(char c: s1)
        freqS1[c-'a']++;
    
    int i = 0, j = 0;

    while(j < s2.size())
    {
        freqS2[s2[j] - 'a']++;

        if(j-i+1 == s1.size())
            if(areEqual(freqS1, freqS2))
                return true;
        
        if(j-i+1 < s1.size())
        {
            j++;
        }
        else 
        {
            freqS2[s2[i] - 'a']--;
            i++;
            j++;
        }
    }

    return false;
}

int main()
{
    string s1;
    cout << "Enter String 1: ";
    cin >> s1;

    string s2;
    cout << "Enter String 2: ";
    cin >> s2;

    if(checkPermutation(s1, s2))
        cout << "Second String contains pallindrome of First String";
    else
        cout << "Second String does contains pallindrome of First String";

}