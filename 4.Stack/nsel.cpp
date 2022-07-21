// Next Smaller Element to the Left
// input:  2 4 1 6 3 5
// output: -1 2 -1 1 1 3

#include<bits/stdc++.hm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Elements: ";
    cin>> n;

    int arr[n];
    int nsel[n];
    cout<<"Enter elements of Array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    stack<int> st;

    nsel[0] = -1;
    st.push(arr[0]);
    for(int i=1; i<=n-1; i++)
    {
        while (st.size()>0 && arr[i]<st.top())
        {
            st.pop();   
        }
        
        if(st.size()==0)
        {
            nsel[i] = -1;
        }
        else
        {
            nsel[i] = st.top();
        }
        st.push(arr[i]);
    }
    

    cout<<"Next Smaller Element to the Left are: ";
    for(int i = 0; i<n; i++)
    {
        cout<<nsel[i] << " ";
    }
}