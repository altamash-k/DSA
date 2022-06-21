#include<bits/stdc++.h>
using namespace std;

void sortMerge(int arr1[], int arr2[], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        if(arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
        }
        sort(arr2, arr2 + m);
    }
}

int main()
{
    int n, m;
    cout << "Enter size of Arr 1: ";
    cin >> n;

    cout << "Enter size of Arr 2: ";
    cin >> m;

    int arr1[n];
    cout << "Enter Arr 1 Elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    int arr2[m];
    cout << "Enter Arr 2 Elements: ";
    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    sortMerge(arr1, arr2, n, m);

    cout << "Array 1 elements after sorting: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\nArray 2 elements after sorting: \n";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    

    return 0;
}