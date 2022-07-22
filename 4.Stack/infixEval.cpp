#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<cctype>

using namespace std;

int precedence(char optor)
{
    if(optor == '+') {
        return 1;
    } else if(optor == '-') {
        return 1;
    } else if(optor == '*') {
        return 2;
    } else {
        return 2;
    }
}

int operation(int v1, int v2, char optor)
{
    if(optor == '+') {
        return v1+v2;
    } else if(optor == '-') {
        return v1-v2;
    } else if(optor == '*') {
        return v1*v2;
    } else {
        return v1/v2;
    }
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    stack<char> stOperator;
    stack<int> stOperand;

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i]; 
        if(ch == '(') {
            stOperator.push(ch);
        } else if(isalnum(ch)) {
            stOperand.push(ch-'0');
        } else if(ch == ')') {
            while (stOperator.top() != '(')
            {
                char optor = stOperator.top();
                stOperator.pop();
                int v2 = stOperand.top();
                stOperand.pop();
                int v1 = stOperand.top();
                stOperand.pop();

                char opv = operation(v1, v2, optor);
                stOperand.push(opv);
            }
            stOperator.pop();
            
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while (stOperator.size() > 0 && stOperator.top() != '(' && precedence(ch) <= precedence(stOperator.top()))
            {
                char optor = stOperator.top();
                stOperator.pop();
                int v2 = stOperand.top();
                stOperand.pop();
                int v1 = stOperand.top();
                stOperand.pop();

                char opv = operation(v1, v2, optor);
                stOperand.push(opv);
            }
            stOperator.push(ch);
        }
    }
}