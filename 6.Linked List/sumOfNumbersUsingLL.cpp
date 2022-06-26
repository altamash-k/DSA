#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insert_l1()
{
    struct node *temp = head1;
    int data;
    cout << "Enter data: ";
    cin >> data;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head1 == NULL)
        head1 = newnode;
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_l2()
{
    struct node *temp = head2;
    int data;
    cout << "Enter data: ";
    cin >> data;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head2 == NULL)
        head2 = newnode;
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display_l1()
{
    struct node *ptr = head1;
    if(head1 == NULL)
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
void display_l2()
{
    struct node *ptr = head2;
    if(head2 == NULL)
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

void sumOfNumbers()
{
    struct node *l1 = head1;
    struct node *l2 = head2;
    struct node *dummy =  (struct node *)malloc(sizeof(struct node));
    struct node *temp = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if(l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = sum % 10;
        temp -> next = newnode;
        temp = temp->next; 
    }

    struct node *ptr = dummy->next;
    while(ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}

int main()
{
    int ch;
	while(1)
	{
		
	cout<<"\nChoose the operations:\n1: Insert a Node in List 1\n2: Insert a Node in List 2\n3: Print List 1\n4: Print List 2\n5: Sum\n"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert_l1();
			break;
		case 2:
			insert_l2();
			break;
		case 3:
			display_l1();
			break;
		case 4:
			display_l2();
			break;
		case 5:
            sumOfNumbers();
            break;
	}		
	}
}