#include<bits/stdc++.h>
using namespace std;

int largestSubArraySumZero(vector<int>& nums)
{
    unordered_map<int, int> ump;
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum == 0)
            maxi = i + 1;
        else
        {
            if(ump.find(sum) != ump.end())
                maxi = max(maxi, i - ump[sum]);
            else
                ump[sum] = i;
        }
    }

    return maxi;
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

    cout << "Longest Sub Arr with Sum 0: " << largestSubArraySumZero(v);

    return 0;
}