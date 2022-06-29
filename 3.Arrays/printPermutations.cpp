#include<bits/stdc++.h>
using namespace std;

void recurPermute(int ind, vector<int>& nums, vector<vector<int>> &ans)
{
    if(ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i < nums.size(); i++)
    {
        swap(nums[i], nums[ind]);
        recurPermute(ind+1, nums, ans);
        swap(nums[i], nums[ind]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

int main()
{
    vector < int > v {1,2,3};
    vector < vector < int >> sum = permute(v);
    cout << "All Permutations are" << endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
    return 0;
}