#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insert_node_l1()
{
    struct node *newNode, *curr;
    int data;
	newNode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data: "<<endl;
	cin>>data;
	newNode->data = data;
	newNode->next = NULL;
    curr = head1;
    if(head1 == NULL || head1->data >= newNode->data) {
        newNode->next = head1;
        head1 = newNode;
        return;
    }
    while(curr->next != NULL && curr->next->data < newNode->data) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}
void insert_node_l2()
{
    struct node *newNode, *curr;
    int data;
	newNode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data: "<<endl;
	cin>>data;
	newNode->data = data;
	newNode->next = NULL;
    curr = head2;
    if(head2 == NULL || head2->data >= newNode->data) {
        newNode->next = head2;
        head2 = newNode;
        return;
    }
    while(curr->next != NULL && curr->next->data < newNode->data) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void print_list_l1()
{
	struct node* p;
	p = head1;
	if(p == NULL)
	{
		cout<<"List is Empty!"<<endl;
	}
	else
	{
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	}
}
void print_list_l2()
{
	struct node* q;
	q = head2;
	if(q == NULL)
	{
		cout<<"List is Empty!"<<endl;
	}
	else
	{
		while(q != NULL)
		{
			cout<<q->data<<" ";
			q = q->next;
		}
	}
}

void merge_lists()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = newNode;
    newNode->next = NULL;
    while(head1!=NULL && head2!=NULL) {
        if(head1->data <= head2->data) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }
    if(head1 != NULL) {
        temp->next = head1;
    }
    else {
        temp->next = head2;
    }
    temp = newNode->next;
    free(newNode);
    return;
}

int main()
{
	int ch;
	while(1)
	{
		
	cout<<"\nChoose the operations:\n1: Insert a Node in List 1\n2: Insert a Node in List 2\n3: Print List 1\n4: Print List 2\n5: Merge Lists"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert_node_l1();
			break;
		case 2:
			insert_node_l2();
			break;
		case 3:
			print_list_l1();
			break;
		case 4:
			print_list_l2();
			break;
		case 5:
			merge_lists();
			break;
		
	}		
	}	
}