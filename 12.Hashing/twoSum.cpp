// input : [2, 1, 5, 8]
// target: 9
// output: [1,3]
// explanation: as index(1) + index(3) = target = 9

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& v, int target)
{
    unordered_map<int, int> umap;
    vector<int> res;
    for(int i = 0; i < v.size(); i++)
    {
        int diff = target - v[i];
        if(umap.find(diff) != umap.end())
        {
            res.push_back(v[diff]);
            res.push_back(i);
            return res;
        }

        umap[v[i]] == i;
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
    
    int target;
    cout << "Enter target value: ";
    cin >> target;

    vector<int> result = twoSum(v, target);
    for(int i:result)
        cout << i << ", ";
}
