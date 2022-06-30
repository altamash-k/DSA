#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    res[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        res[i] += res[i-1] + nums[i];
    }
    
    return res;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int data;
    vector<int> nums;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        nums.push_back(data);
    }

    vector<int> res = runningSum(nums);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}