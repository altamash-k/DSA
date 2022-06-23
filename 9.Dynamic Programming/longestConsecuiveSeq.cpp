#include<bits/stdc++.h>
using namespace std;

int longestStreak(vector<int>& nums)
{
    set<int> hashSet;
    for(int num : nums)
        hashSet.insert(num);
    
    int longestStreak = 0;

    for(int num: nums)
    {
        if(!hashSet.count(num - 1))
        {
            int currentStreak = 1;
            int currentNum = num;

            while (hashSet.count(currentNum + 1))
            {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
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

    cout << "Longest Streak: " << longestStreak(v);
}