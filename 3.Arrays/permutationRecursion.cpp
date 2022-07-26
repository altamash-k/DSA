#include<bits/stdc++.h>
using namespace std;

void solvePermuation(int ind, vector<int>& nums, vector<vector<int>>& ans)
{
    if(ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        solvePermuation(ind+1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permutation(vector<int>& nums)
{
    vector<vector<int>> ans;
    solvePermuation(0, nums, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> nums;
    cout << "Enter nums: ";
    for(int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        nums.push_back(data);
    }

    vector < vector < int >> sum = permutation(nums);
    cout << "All Permutations are" << endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
        cout << sum[i][j] << " ";
        cout << endl;
    }
}