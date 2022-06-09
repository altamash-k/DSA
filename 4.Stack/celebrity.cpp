#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
main() 
{  
    int r, c;
    stack<int> st;
    cout << "Enter number of Rows: " << endl;
    cin >> r;
    cout << "Enter number of Columns: " << endl;
    cin >> c;
    int  s[r][c];
    int  i, j;
    cout<<"\n2D Array Input:\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<"\ns["<<i<<"]["<<j<<"]=  ";
            cin>>s[i][j];
        }
    } 
    
    cout<<"\nThe 2-D Array is:\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<"\t"<<s[i][j];
        }
    cout<<endl;
    } 
    
    // logic for celebrity problem starts here
    for(int i = 0; i < r; i++)
    {
        st.push(i);
    }

    while(st.size() >= 2)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();

        if(s[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int pot = st.top();
    st.pop();
    for(int i = 0; i < r; i++)
    {
        if(i!=pot)
        {
            if(s[i][pot] == 0 || s[pot][i] == 1)
            {
                cout << "No Celebrity Founnd" << endl;
                return 0;
            }
        }
    }
    cout << "Celebrity is: " << pot;

    
} 