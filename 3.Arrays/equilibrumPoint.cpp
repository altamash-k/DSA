#include<bits/stdc++.h>
using namespace std;

int equilibrum(int arr[], int n)
{
    int sum_left = 0;
    int sum_right = 0;
    for(int i = 1; i < n; i++)
    {
        sum_right += arr[i];
    }

    for(int i = 0, j = 1; j < n; i++, j++)
    {
        sum_right -= arr[j];
        sum_left += arr[i];
        if(sum_left == sum_right)
            return arr[i+1];
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 4, 2, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Equilibrum point is: " << equilibrum(arr, n);
    return 0;
}