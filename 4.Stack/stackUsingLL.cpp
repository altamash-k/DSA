#include<bits/stdc++.hm>
#include<bits/stdc++.h>

using std::cout;
using std::cin;

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    if(top == NULL)
        cout<<"Stack underflow\n";
    temp = top;
    top = top->next;
    return temp->data;
    free(temp);
}

int peek()
{
    struct node *temp;
    if(top == NULL)
        cout<<"Stack underflow\n";
    temp = top;
    return temp->data;
}

int size()
{
    struct node *temp;
    if(top == NULL)
        cout<<"Stack underflow\n";
    temp = top;
    int count = 0;
    while (temp->next!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return (count+1);
}

int display()
{
    struct node *temp;
    if(top == NULL)
        cout<<"Stack underflow\n";
    temp = top;
    cout << temp->data << "->";
    while (temp->next!=NULL)
    {
        temp = temp->next;
        cout << temp->data << "->";
    }
}

int main() {
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