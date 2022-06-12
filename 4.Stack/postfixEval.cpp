#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;

    string expr;
    cout << "Enter the String: ";
    cin >> expr;
    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if(isalnum(ch))
            st.push(ch);
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();
            int res;
            switch (ch)
            {
            case '+':
                res = top1 + top2;
                st.push(res);
                break;
            case '-':
                res = top1 - top2;
                st.push(res);
                break;
            case '*':
                res = top1 * top2;
                st.push(res);
                break;
            case '/':
                res = top1 / top2;
                st.push(res);
                break;
            
            default:
                break;
            }
        }
    }
    int ans = st.top();
    st.pop();
    cout << ans;
    
    
}