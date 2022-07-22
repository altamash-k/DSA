#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[n];
    cout<<"Enter value of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int max = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int floor = max; floor >= 1; floor--)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= floor)
            {
                cout<<"*\t";
            }
            else
            {
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
}