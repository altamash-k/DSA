#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 2;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] == nums[mid^1])
            low = mid + 1;
        else 
            high = mid-1;
    }

    return nums[low];
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

    cout << "Single element is: " << singleElement(nums);

    return 0;
}