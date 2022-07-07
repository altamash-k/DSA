/*
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i]
    Ex. nums = [1,2,3,4] -> [24,12,8,6], nums = [-1,1,0,-3,3] -> [0,0,9,0,0]

    Calculate prefix products forward, then postfix backwards in a 2nd pass

    Time: O(n)
    Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> prodOfArr(vector<int>& nums)
{
    int n = nums.size();
    vector<int> res (n, 1);

    int prefix = 1;
    for(int i = 0; i < n; i++)
    {
        res[i] = prefix;
        prefix = prefix * nums[i];
    }

    int postfix = 1;
    for(int i = n-1; i >= 0; i--)
    {
        res[i] = res[i] * postfix;
        postfix = postfix * nums[i];
    }

    return res;
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

    vector<int> result = prodOfArr(v);
    for(int i:result)
        cout << i << ", ";
}