#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& nums, int k)
{
    priority_queue<int> pq;
    for(int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }

    int f = k-1;
    while(f > 0)
    {
        pq.pop();
        f--;
    }

    cout << k << "-Largest element is: " << pq.top() << endl;
}

int kthSmallest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }

    int f = k-1;
    while(f > 0)
    {
        pq.pop();
        f--;
    }

    cout << k << "-Smallest element is: " << pq.top() << endl;
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

    int k;
    cout << "Enter k:";
    cin >> k;

    kthLargest(nums, k);
    kthSmallest(nums, k);

    return 0;
}