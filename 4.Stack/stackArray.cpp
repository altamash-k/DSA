#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<limits.h>
#define n 5

using std::cout;
using std::cin;

int stack[n];
int top = -1;

void push(int data) {
    if(top == n-1)
        cout<<"Stack overflow" << "\n";
    else {
        top++;
        stack[top] = data;
    }
}

int pop() {
    if(top == -1)
        cout<<"Stack underflow" << "\n";
    else {
        int item = stack[top];
        top--;
        return item;
    }
    return 0;
}

int peek() {
    if(top == -1)
        cout<<"Stack underflow" <<  "\n";
    else {
        int item = stack[top];
        return item;
    }
    return 0;
}

int size() {
    if(top == -1)
        cout<<"Stack underflow" <<  "\n";
    else
        return (top+1);
    return 0;
}

int display() {
    if(top == -1)
        cout<<"Stack underflow" <<  "\n";
    else {
        for (int i = top; i >= 0; i--)
        {
            // return stack[i];
            cout<<stack[i]<<"->";
        }
        
    }

    return 0;
}

int main() {
    int i = 0;

    int ch;
    
    while (1)
    {
        cout<<"\n1. Push \n2. Pop \n3. Peek \n4. Size \n5. Display Stack\n";
        cout<<"Enter choice: \n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            int data;
            cout<<"Enter data: ";
            cin>>data;
            push(data);
            break;

        case 2:
            cout<<"Popped element is: " << pop() << "\n";
            break;
        
        case 3: 
            cout<<"Top element is: " << peek() << "\n";;
            break;
        case 4:
            cout<<"Size of stack is: " << size() << "\n";
            break;
        case 5:
            cout<< "Stack elements: " << display();
        default:
            break;
        }
    }
    return 0;
}