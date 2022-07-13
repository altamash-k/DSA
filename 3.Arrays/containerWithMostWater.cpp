/*
    Given array of heights, find max water container can store
    Ex. height = [1,8,6,2,5,4,8,3,7] -> 49, (8 - 1) x min(8, 7)

    2 pointers outside in, greedily iterate pointer w/ lower height

    Time: O(n)
    Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maxContainer(vector<int> height)
{
    int i = 0;
    int j = height.size()-1;
    int curr = 0;
    int res = 0;

    while(i < j)
    {
        curr = (j-1) * min(height[j], height[i]);
        res = max(res, curr);

        if(height[i] <= height[j])
            i++;
        else
            j--;
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int data;
    vector<int> v;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    cout << "Max water will be: " << maxContainer(v);
}