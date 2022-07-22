#include<bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;
int main()
{   
    stack<int> st;
    string expr;
    cout << "Enter String: " << endl;
    cin >> expr;
    int num = 1;
    for(int i=0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if(ch = 'd')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;
            while(st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    st.push(num);
    while(st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}