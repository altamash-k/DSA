#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_node()
{
    struct node *newNode, *curr;
    int data;
	newNode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data: "<<endl;
	cin>>data;
	newNode->data = data;
	newNode->next = NULL;
    curr = head;
    if(head == NULL || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    while(curr->next != NULL && curr->next->data < newNode->data) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void print_list()
{
	struct node* p;
	p = head;
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

int main()
{
	int ch;
	while(1)
	{
		
	cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert_node();
			break;
		case 2:
			print_list();
			break;
		
	}		
	}	
}