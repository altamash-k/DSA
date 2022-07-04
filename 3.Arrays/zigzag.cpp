#include<bits/stdc++.h>
using namespace std;

void zigZag(int arr[], int n)
{
    for(int i = 1; i < n; i += 2)
    {
        if(arr[i-1] > arr[i])
            swap(arr[i-1], arr[i]);
        if(i+1 < n && arr[i+1] > arr[i])
            swap(arr[i+1], arr[i]);
    }
}

int main()
{
    int arr[] = { 4, 3, 7, 8, 6, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    zigZag(arr, n);
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]";
    return 0;
}