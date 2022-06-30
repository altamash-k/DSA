#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size()-1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[low] <= nums[mid])
        {
            if(nums[low] <= target && nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if(nums[mid] <= target && target <=  nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
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

    int target;
    cout << "Enter target:";
    cin >> target;

    cout << "Element found: " << search(nums, target);
    return 0;
}