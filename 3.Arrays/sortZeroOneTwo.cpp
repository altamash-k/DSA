#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter Array Elements: ";
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        
        default:
            break;
        }

    }

    cout << "After sorting array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}