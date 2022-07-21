// Remove Adjacent duplicates
// input: career
// output: ca

#include<bits/stdc++.hm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> st;

    string str;
    cout << "Enter the String: ";
    cin >> str;
    int i = 0;
    while(i < str.length())
    {
        char ch = str[i];
        if (st.size() == 0 || ch != st.top())  
        {
            st.push(ch);
            i++;
        }
        else
        {
            st.pop();
            i++;
        } 
    }
    string ans = "";
    if(st.empty())
    {
        cout << "Empty Stack";
    }
    else
    {
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
    }

    cout << "Output: " << ans;
}