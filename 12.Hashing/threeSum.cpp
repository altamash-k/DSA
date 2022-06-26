#include<bits/stdc++.h>
using namespace std;

vector<int> threeSum(vector<int>& nums, int target)
{
    vector<int> res;
    vector<int> tripplet(3, 0);
    int n = nums.size();
    if(nums.empty())
        return res;

    sort(nums.begin(), nums.end());
    int i, j;
    for(i = 0; i < n; i++)
    {
        int target2 = target - nums[i];
        int front = i + 1;
        int back = n - 1;

        while(front < back)
        {
            int two_sum = nums[front] + nums[back];
            if(two_sum < target2)
                front++;
            else if(two_sum > target2)
                back--;
            else
            {
                tripplet[0] = nums[i];
                tripplet[1] = nums[front];
                tripplet[2] = nums[back];

                for(int i = 0; i < tripplet.size(); i++)
                    res.push_back(tripplet[i]);
                
                // for finding duplicates:
                while(front < back && nums[front] == tripplet[1])
                    ++front;

                while(front < back && nums[back] == tripplet[2])
                    --back;
            }
        }

        while(i + 1 < n && nums[i + 1] == nums[i])
            ++i;
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

    vector<int> result = threeSum(v, target);

    cout << "All the tripplet pairs would be: ";
    for(int i=0; i < result.size(); i++)
    {
        if(i % 3 == 0)
            cout << endl;
        cout << result[i] << " ";
    }
}