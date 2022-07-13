/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void generate(int n, int open, int close, string str, vector<string>& res)
{
    if(open == n && close == n)
    {
        res.push_back(str);
        return;
    }

    if(open < n)
        generate(n, open+1, close, str + "(", res);
    if(open > close)
        generate(n, open, close+1, str + ")", res);
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    generate(n, 0, 0, "", res);
    return res;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> res = generateParenthesis(n);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}