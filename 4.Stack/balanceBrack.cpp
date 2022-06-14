#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    stack<char>st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if(ch == ')') {
            if(st.size() != 0 && st.top() == '(') {
                st.pop();
            }
            else {
                cout << "false" << endl;
                break;
            }
        }
        else if(ch == '}') {
            if(st.size() != 0 && st.top() == '{') {
                st.pop();
            }
            else {
                cout << "false" << endl;
                break;
            }
        }
        else if(ch == ']') {
            if(st.size() != 0 && st.top() == '[') {
                st.pop();
            }
            else {
                cout << "false" << endl;
                break;
            }
        }
    }
    if(st.size() != 0) {
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
    }
}
