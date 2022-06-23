#include<bits/stdc++.h>
using namespace std;

vector<int> fourSum(vector<int>& nums, int target)
{
    vector<int> res;
    vector<int> quadruplet(4, 0);
    int n = nums.size();
    if(nums.empty())
        return res;

    sort(nums.begin(), nums.end());
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            int target2 = target - nums[j] - nums[i];
            int front = j + 1;
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
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[front];
                    quadruplet[3] = nums[back];
                    for(int i = 0; i < quadruplet.size(); i++)
                        res.push_back(quadruplet[i]);

                    while(front < back && nums[front] == quadruplet[2])
                        ++front;

                    while(front < back && nums[back] == quadruplet[3])
                        --back;
                }
            }

            while(j + 1 < n && nums[j + 1] == nums[j])
                ++j;
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

    vector<int> result = fourSum(v, target);

    cout << "All the quadruplet pairs would be: ";
    for(int i=0; i < result.size(); i++)
    {
        if(i % 4 == 0)
            cout << endl;
        cout << result[i] << " ";
    }
}