#include<iostream>
#include<bits/stdc++.h>
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
    struct node *temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
    }
    else
    {
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
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
        insert_begin();
    else
    {
        while(temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
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
        struct node *toDel = head;
        
        while(temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        cout << "Deleted node is: " << toDel->data;
        free(toDel);
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
        while (prev->next->next != head)
        {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = head;
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
        do
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        } while (ptr != head);
    }
}
int main()
{
    cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Delete at Beginning\n5:Delete at Middle\n6:Delete at End\n7:Print the List\n"<<endl;
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
		
        default:
            break;
	}		
	}
}