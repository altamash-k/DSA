#include<bits/stdc++.h>
using namespace std;

vector<int> kFreqEle(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int>mp;
    for(int i = 0; i < n; i++)
        mp[nums[i]]++;
    
    vector<vector<int>> buckets(n+1);
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        buckets[it->second].push_back(it->first);
    }

    vector<int> res;
    for(int i = n; i > 0; i--)
    {
        if(res.size() >= k)
            break;

        if(!buckets[i].empty())
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
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
    
    int k;
    cout << "Enter k value: ";
    cin >> k;

    vector<int> result = kFreqEle(v, k);
    for(int i:result)
        cout << i << ", ";
}