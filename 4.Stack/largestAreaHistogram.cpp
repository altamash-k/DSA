#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout<<"Enter height of Histogram: ";
    cin >> arr[n];

    // For Right Boundary

    stack<int> str;
    int rb[n];
    rb[n-1] = n;
    str.push(n-1);
    for(int i=n-2; i>=0; i--)
    {
        while (str.size()>0 && arr[i] < arr[str.top()])
        {
            str.pop();   
        }
        
        if(str.size()==0)
        {
            rb[i] = n;
        }
        else
        {
            rb[i] = str.top();
        }
        str.push(i);
    }

    // For Left Boundary

    stack<int> stl;
    int lb[n];
    lb[0] = -1;
    stl.push(0);
    for(int i=1; i<n; i++)
    {
        while (stl.size()>0 && arr[i]< arr[stl.top()])
        {
            stl.pop();   
        }
        
        if(stl.size()==0)
        {
            lb[i] = -1;
        }
        else
        {
            lb[i] = stl.top();
        }
        stl.push(i);
    }

    //For Area of Histogram
    int maxArea = 0;
    for(int i = 0; i<n; i++)
    {
        int width = rb[i]-lb[i]-1;
        int height = arr[i];
        int area = height * width;
        if(area>maxArea)
        {
            maxArea = area;
        }
    }

    cout << "Largest Area of the Histogram is: " << maxArea;
}