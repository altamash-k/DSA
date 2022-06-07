#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of elements in array: ";
    cin >> n;

    int arr[n];
    cout<<"Enter values of Array: " <<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }

    int span = max - min;
    cout << "Span of the Array is: " << span << endl;
}