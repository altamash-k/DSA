#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin()
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insert_pos()
{
    struct node *temp = head;
    int data;
    cout << "Enter data: ";
    cin >> data;

    int pos, i=1;
    cout << "Enter position: ";
    cin >> pos;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void insert_end()
{
    struct node *temp = head;
    int data;
    cout << "Enter data: ";
    cin >> data;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void delete_begin()
{
    struct node *temp = head;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        head = head->next;
        cout << "Deleted node is: " << temp->data;
        free(temp);
    }
}
void delete_pos()
{
    struct node *temp = head, *nextnode;
    int pos, i=1;
    cout << "Enter position to delete: ";
    cin >> pos;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        cout << "Deleted node is: " << nextnode->data;
        free(nextnode);
    }
}
void delete_end()
{
    struct node *temp, *prev = head;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        while (prev->next->next != NULL)
        {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = NULL;
        cout << "Deleted node is: " << temp->data;
        free(temp);
    }
}

void display()
{
    struct node *ptr = head;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
    }
}

void reverse()
{
    struct node *prev, *curr, *nextnode;
    prev = NULL;
    curr = nextnode = head;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        while (nextnode != NULL)
        {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        head = prev;
    }
}

void kthNodeEnd()
{
    struct node *slow = head;
    struct node *fast = head;
    int k;
    cout<<"Enter value of k: ";
    cin >> k;
    for(int i = 0; i<k; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    cout << "Kth element from end will be: " << slow->data << "\n";
}

void middle()
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element is: " << slow->data << "\n";
    
}

int main()
{
    cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Delete at Beginning\n5:Delete at Middle\n6:Delete at End\n7:Print the List\n8.Reverse\n9.Kth Node from End\n10.Middle"<<endl;
    int ch;
	while(1)
	{
    cout << "\nEnter choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			insert_begin();
			break;
		case 2:
			insert_pos();
			break;
		case 3:
			insert_end();
			break;
		case 4:
			delete_begin();
			break;
		case 5:
			delete_pos();
			break;
		case 6:
			delete_end();
			break;
		case 7:
			display();
			break;
		case 8:
			reverse();
			break;
		case 9:
			kthNodeEnd();
			break;
		case 10:
			middle();
			break;
        default:
            break;
	}		
	}
}