#include<bits/stdc++.h>
using namespace std;

vector<int> majorityEl(int nums[], int n)
{
    int sz = n;
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    for(int i = 0; i < sz; i++)
    {
        if(nums[i] == num1)
            count1++;
        else if(nums[i] == num2)
            count2++;
        else if(count1 == 0)
        {
            num1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0)
        {
            num2 = nums[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for(int i = 0; i < sz; i ++)
    {
        if(nums[i] == num1)
            count1++;
        else if(nums[i] == num2)
            count2++;
    }

    vector<int> ans;
    if(count1 > sz/3)
        ans.push_back(num1);
    if(count2 > sz/3)
        ans.push_back(num2);

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of values: ";
    cin >> n;

    int arr[n];
    cout << "Enter value of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
        
    vector<int> majority;
    majority = majorityEl(arr, n);
    cout << "Majority Elements are: ";
    for(auto it : majority)
        cout << it << " ";
}