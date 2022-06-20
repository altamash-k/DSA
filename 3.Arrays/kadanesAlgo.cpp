/*
Enter no of elements: 8
Enter values: -2 -3 4 -1 -2 1 5 -3
Gretest Sum is: 7 
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> v)
{
    int sum = 0;
    int maxi = INT_MIN;
    for(auto i: v)
    {
        sum += i;
        maxi = max(sum, maxi);
        if(sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int data;
    vector<int> v;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }

    cout << "Greatest Sum is: " << maxSubArray(v) << " ";

    return 0;
}