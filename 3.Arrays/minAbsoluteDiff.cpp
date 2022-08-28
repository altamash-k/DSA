#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getMinAbsDiff(vector<int>& arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int diff = abs(arr[0]-arr[1]);
    ans.push_back({arr[0], arr[1]});
    
    for(int i = 1; i < arr.size()-1; i++)
    {
        int dff = arr[i+1]-arr[i];
        if(dff < diff)
        {
            while(ans.size())
            {
                ans.pop_back();
            }
        }
        if(dff == diff)
        {
            ans.push_back({arr[i], arr[i+1]});
        }
    }
    
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr;
    int data;
    cout << "Enter Elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    vector<vector<int>> ans = getMinAbsDiff(arr);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
    }

}