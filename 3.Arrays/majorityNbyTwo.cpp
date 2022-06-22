#include <bits/stdc++.h>
using namespace std;

int majority(vector<int>& nums)
{
    int count = 0;
    int candidate = 0;
    for(int num: nums)
    {
        if(count == 0)
            candidate = num;
        if(num == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

int main()
{
    vector<int> nums;

    int n;
    cout << "Enter number of values: ";
    cin >> n;

    int data;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        nums.push_back(data);
    }

    cout << "Majority element is: ";
    cout << majority(nums);
}