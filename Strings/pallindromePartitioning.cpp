#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void func(int ind, string s, vector<vector<string>>& res, vector<string>& path)
{
    if(ind == s.size())
    {
        res.push_back(path);
        return;
    }

    for(int i = ind; i < s.size(); i++)
    {
        if(isPallindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            func(i+1, s, res, path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, res, path);
    return res;
}



int main()
{
    string s = "aabb";
    vector < vector < string >> ans = partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i: ans) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}