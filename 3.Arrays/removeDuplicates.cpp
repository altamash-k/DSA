#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    /* this is using the fast and slow pointer
    slow incremented by one, and fast by two.
    */
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    fast = nums[0]; //setting fast to first element
    while (slow != fast)
    {
        // increment fast and slow one by one
        slow = nums[slow];
        fast = nums[fast];
    }
    
    //point at which they meet will be the answer
    return slow;
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

    cout << "Duplicate element is: ";
    cout << removeDuplicates(v);
}