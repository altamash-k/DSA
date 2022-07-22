#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"Enter Window Size: ";
    cin>>k;

    int nge[n];

    stack<int> st;

    //For Next Greater Element
    nge[n-1] = n;

    st.push(n-1);

    for (int i = n-2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i]>arr[st.top()])
        {
            st.pop();
        }
        if(st.size() == 0)
        {
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    
    // For Sliding Window
    int j = 0;

    for(int i = 0; i<n-k+1; i++)
    {
        if(j<i)
        {
            j = i;
        }
        
        while (nge[j] < i+k)
        {
            j = nge[j];
        }
        cout << arr[j] << " ";
    }
}