#include<iostream>
#include<bits/stdc++.h>
#define n 5

using std::cout;
using std::cin;

int queue[n];
int head = -1, tail = -1;

int enqueue(int data)
{
    if(tail == n-1)
        cout<<"Queue overflow \n";
    else if(head == -1 && tail == -1) //for one element
    {   
        head = tail = 0;
        queue[tail] = data;
    }
    else
    {
        tail++;
        queue[tail] = data;
    }

    return 0;
}

int dequeue()
{
    if(head == -1 && tail == -1)
        cout<<"Queue underflow";
    else if(head == tail) //for one element
    {
        head = tail = -1;
    }  
    else
    {
        int temp = head;
        head++;
        return queue[temp];
    } 
}

int display()
{
    if(head == -1 && tail == -1)
        cout<<"Queue underflow";
    else
    {
        for (int i = head; i < tail + 1; i++)
        {
            cout << queue[i];
            cout<<"->";
        }
    }
}

int top()
{
    if(head == -1 && tail == -1)
        cout<<"Queue underflow";
    else
    {
        int top = head;
        return queue[top];
    }
}

int size()
{
    int count;
    if(head == -1 && tail == -1)
        cout<<"Queue underflow";
    else if(head == tail)
    {
        count = 1;
    }
    else
    {
        count = tail - head + 1;
    }

    return count;
}

int main()
{
    int ch;
    while (1)
    {
        cout<<"\n1. Enqueue \n2. Dequeue \n3. Display Stack\n4. Top\n5. Size\n";
        cout<<"Enter choice: \n";
        cin>>ch;
        switch (ch)
        {
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                enqueue(data);
                break;

            case 2:
                cout<<"Dequeued element is: " << dequeue() << "\n";
                break;
            
            case 3:
                cout<< "Queue elements: " << display() << "\n";
                break;
            case 4: 
                cout << "Top Element is: " << top() << "\n";
                break;;
            case 5:
                cout << "Queue Size is: " << size() << "\n";
                break;
            default:
                break;
        }
    }
    return 0;
}