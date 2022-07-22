#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = 0, *tail = 0;

int enqueue(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL && tail == NULL)
    {
        head = tail = newnode;

    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int dequeue()
{
    if(head == NULL && tail == NULL)
    {
        cout << "Queueu Underflow";
    }
    else if(head==tail)
    {
        head = tail = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        return temp->data;
        free(temp);
    }
}

int display()
{
    struct node* p;
	p = head;
    if(head == NULL && tail == NULL)
    {
        cout << "Queueu Underflow";
    }
	else
	{
		while(p != NULL)
		{
			cout<<p->data<<"->";
			p = p->next;
		}
	}
}

int top()
{
    if(head == NULL && tail == NULL)
    {
        cout << "Queueu Underflow";
    }
    return head->data;
}

int size()
{
    int count = 0;
    if(head == NULL && tail == NULL)
    {
        cout << "Queueu Underflow";
    }
    else if(head == tail)
    {
        count = 1;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != tail)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int ch;
    while (1)
    {
        cout<<"\n1. Enqueue \n2. Dequeue \n3. Display Queue\n4. Top\n5. Size\n";
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