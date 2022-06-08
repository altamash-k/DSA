// Next Smaller Element to the Right
// input:  2 4 1 6 3 5
// output: 1 1 -1 3 -1 -1

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin>> n;

    int arr[n];
    int nser[n];
    cout<<"Enter elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans;
    stack<int> st;

    nser[n-1] = -1;
    st.push(arr[n-1]);
    for(int i=n-2; i>=0; i--)
    {
        while (st.size()>0 && arr[i]<st.top())
        {
            st.pop();   
        }
        
        if(st.size()==0)
        {
            nser[i] = -1;
        }
        else
        {
            nser[i] = st.top();
        }
        st.push(arr[i]);
    }
    

    cout<<"Next Smaller Element to the Right are: ";
    for(int i = 0; i<n; i++)
    {
        cout<<nser[i] << " ";
    }
}