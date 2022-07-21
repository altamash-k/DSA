#include<bits/stdc++.hm>
#include<stack>
using namespace std;

stack<int> st1;
stack<int> st2;

void enqueue()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    st1.push(data); 
}

int dequeue()
{
    if(st1.empty() && st2.empty())
        cout << "Queue is empty";
    else if(st2.empty())
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int topVal = st2.top();
    st2.pop();

    return topVal;
}

// int display()
// {
//     for(int i = 0; i<=st1.size()-1; i++)
//     {
//         cout << st1.pop() << " ";
//     }
// }

int top()
{
    return st2.top();
}

int size()
{
    return st2.size();
}
int main()
{
    int ch;
    while (1)
    {
        cout<<"\n1. Enqueue \n2. Dequeue\n3. Top\n4. Size\n";
        cout<<"Enter choice: \n";
        cin>>ch;
        switch (ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                cout<<"Dequeued element is: " << dequeue() << "\n";
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