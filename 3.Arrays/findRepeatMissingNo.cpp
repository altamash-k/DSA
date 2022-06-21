// Find the repeating and missing number
// input : 3, 1, 2, 5, 3
// output : 3, 4
// explanaion: As 3 is repeating and 4 is missing 

#include<bits/stdc++.h>
using namespace std;

int repeating_missing_no(vector<int>& nums)
{
    int n = nums.size() + 1;
    vector<int> substitute(n, 0);
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        substitute[nums[i]]++;
    }
    for(int i = 1; i < n; i++)
    {
        if(substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    cout << "Ans: ";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter no of values: ";
    cin >> n;

    int data;
    vector<int> v;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    repeating_missing_no(v);
}