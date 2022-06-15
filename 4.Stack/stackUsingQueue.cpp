#include<iostream>
#include<queue>
using namespace std;

queue<int> q1;
queue<int> q2;

void push()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    q1.push(data);
}

int pop()
{
    if(q1.empty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
        
    while(q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int popVal = q1.front();
    q1.pop();

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    return popVal;
}

int top()
{
    if(q1.empty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
        
    while(q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int topVal = q1.front();
    q2.push(topVal);

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    return topVal;
}

int size()
{
    return q1.size();
}

int main()
{
    int ch;
    while (1)
    {
        cout<<"\n1. Push \n2. Pop\n3. Top\n4. Size\n";
        cout<<"Enter choice: \n";
        cin>>ch;
        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                cout<<"Popped element is: " << pop() << "\n";
                break;
            case 3: 
                cout << "Top Element is: " << top() << "\n";
                break;;
            case 4:
                cout << "Queue Size is: " << size() << "\n";
                break;
            default:
                break;
        }
    }

    return 0;
}