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
    // return 0;
}
void delete_pos()
{
    // return 0;
}
void delete_end()
{
    // return 0;
}

void display()
{
    struct node *temp = head;
    if(temp == NULL)
        cout << "List is empty";
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
	while(1)
	{
		
	cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Delete at Beginning\n5:Delete at Middle\n6:Delete at End\n7:Print the List\n"<<endl;
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