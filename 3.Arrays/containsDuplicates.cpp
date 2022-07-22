#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    cout << "Array elements sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int duplicates = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == arr[i+1])
            duplicates = 1;
    }
    if(duplicates == 1)
        cout << "\nContains duplicates";
    else
        cout << "\nNo duplicates";
    
}