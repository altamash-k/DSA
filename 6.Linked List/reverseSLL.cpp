#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
	struct node* temp;
	int data;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data"<<endl;
	cin>>data;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}else{
		struct node* p;
		p = head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
}

void reverse()
{
    struct node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int length()
{
	struct node *temp = head;
	int length = 0;
	while(temp != NULL)
	{
		++length;
		temp = temp->next;
	}

	return length;
}

void reverseKNodes()
{
	struct node *prev, *curr, *next;
	struct node *dummyNode = (struct node*)malloc(sizeof(struct node));
	dummyNode->data = 0;
	dummyNode->next = head;
	prev = dummyNode;

	int len = length();
	int k;
	cout << "Enter value of k: ";
	cin >> k;

	while(len >= k)
	{
		curr = prev->next;
		next = curr->next;
		for(int i = 1; i < k; i++)
		{
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		prev = curr;
		len -= k;
	}
	
	head = dummyNode->next;
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
		
	cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Reverse the List\n4: Reverse K nodes\n"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			print_list();
			break;
		case 3:
			reverse();
			break;
		case 4:
			reverseKNodes();
			break;
		
	}		
	}	
}