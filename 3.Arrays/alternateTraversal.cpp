#include<bits/stdc++.h>
using namespace std;

void alternate(int arr[], int n)
{
    sort(arr, arr+n);
    cout << arr[n-1] << " ";
    int i = 0, j = n-2;
    while(i < j)
    {
        cout << arr[i] << " ";
        i++;
        cout << arr[j] << " ";
        j--;
    }
    cout << arr[j] << " ";
}

int main()
{
    int arr[] = { 4, 1, 5, 2, 3, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    alternate(arr, n);

    return 0;
}