/*
Enter n: 6
Enter values: 1 1 0 1 1 1
Maximum Consecutive Ones are: 3
*/

#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> arr)
{
    int count = 0, maxCount = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            count++;
            if(count > maxCount)
                maxCount = count;
        }
        else if(arr[i] == 0)
            count = 0;
    }

    return maxCount;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int data;
    vector<int> arr;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }

    cout << "Maximum Consecutive Ones are: " << maxConsecutiveOnes(arr);
    return 0;
}
