#include<bits/stdc++.h>
using namespace std;

void printAns(vector<vector<int>>& ans)
{
    cout << "The unique subsets are: ";
    cout << "[";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]";
}

void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
{
    ans.push_back(ds);
    for(int i = ind; i < nums.size(); i++)
    {
        if(i != ind && nums[i] == nums[i-1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i+1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
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

    vector<vector<int>> ans = subsetsWithDup(nums);
    printAns(ans);

    return 0;
}