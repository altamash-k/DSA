// Next Greater Element to the Left
// input:  2 4 1 6 3 5
// output: -1 -1 4 -1 6 6

#include<bits/stdc++.hm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin>> n;

    int arr[n];
    int ngel[n];
    cout<<"Enter elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    stack<int> st;

    ngel[0] = -1;
    st.push(arr[0]);
    for(int i=1; i<=n-1; i++)
    {
        while (st.size()>0 && arr[i]>st.top())
        {
            st.pop();   
        }
        
        if(st.size()==0)
        {
            ngel[i] = -1;
        }
        else
        {
            ngel[i] = st.top();
        }
        st.push(arr[i]);
    }
    

    cout<<"Next Greater Elements to the Left are: " <<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<ngel[i] << " ";
    }
}