/*
    Evaluate RPN, valid operators: +, -, *, /

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

    Stack, if num push, if operator apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int eval(vector<string>& tokens)
{
    stack<int> st;
    for(int i = 0; i < tokens.size(); i++)
    {
        string token = tokens[i]; // get each token
        if(token.size() > 1 || isdigit(token[0])) // if num
        {
            st.push(stoi(token)); // push digit value
            continue; // continue from loop
        }

        int num2 = st.top(); // take first nun
        st.pop();
        int num1 = st.top(); // take second num
        st.pop();

        int res = 0;

        // apply required operation
        if(token == "+")
            res = num1 + num2;
        else if(token == "-")
            res = num1-num2;
        else if(token == "*")
            res = num1*num2;
        else
            res = num1/num2;
        
        st.push(res);
    }

    return st.top();
}

int main()
{
    vector<string> tokens = {"4","13","5","/","+"};
 
    int res = eval(tokens);
    cout << res << endl;
}