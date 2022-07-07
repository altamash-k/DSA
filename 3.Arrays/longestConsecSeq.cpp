/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    int n = nums.size();
    unordered_set<int>s;
    for(int i = 0; i < n; i++)
        s.insert(nums[i]); // store all the elements of arr in set that will make it sort
    
    int res = 0;
    for(auto it = s.begin(); it != s.end(); it++) // iterator
    {
        int curr = *it; // pointing at curr ele
        if(s.find(curr-1) != s.end()) // find if its the first number of seq, by checking any value which is lesser than it
            continue;
        
        int currLength = 1;
        while(s.find(curr + 1) != s.end()) // now check if any next consecutive ele is present or not
        {
            currLength++; // if present increase length
            curr++; // increase ele
        }
        res = max(res, currLength); // get the max length
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

    cout << "Longest Consecutive Seq is: " << longestConsecutive(v);

}