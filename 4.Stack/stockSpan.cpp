// Stock Span
// input:  2 4 1 6 3 5
// output: 1 2 1 4 1 2

#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin>> n;

    int arr[n];
    int span[n];
    cout<<"Enter elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    stack<int> st;

    span[0] = 1;
    st.push(0);
    for(int i=1; i<=n-1; i++)
    {
        while (st.size()>0 && arr[i]>arr[st.top()])
        {
            st.pop();   
        }
        
        if(st.size()==0)
        {
            span[i] = i+1;
        }
        else
        {
            span[i] = i-st.top();
        }
        st.push(i);
    }
    

    cout<<"Stock Span are: ";
    for(int i = 0; i<n; i++)
    {
        cout<<span[i] << " ";
    }
}