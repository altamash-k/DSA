// Next Greater Element to the Right
// input:  2 4 1 6 3 5
// output: 4 6 6 -1 5 -1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin>> n;

    int arr[n];
    int nger[n];
    cout<<"Enter elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans;
    stack<int> st;

    nger[n-1] = -1;
    st.push(arr[n-1]);
    for(int i=n-2; i>=0; i--)
    {
        while (st.size()>0 && arr[i]>st.top())
        {
            st.pop();   
        }
        
        if(st.size()==0)
        {
            nger[i] = -1;
        }
        else
        {
            nger[i] = st.top();
        }
        st.push(arr[i]);
    }
    

    cout<<"Next Greater Elements to the Right are: ";
    for(int i = 0; i<n; i++)
    {
        cout<<nger[i] << " ";
    }
}