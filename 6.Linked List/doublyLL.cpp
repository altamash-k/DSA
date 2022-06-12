#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert_begin()
{
	struct node* temp;
	int data;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data: "<<endl;
	cin>>data;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}else{
		temp->next = head;
        head->prev = temp;
		head = temp;
        temp->prev = NULL;
	}
	
}

void insert_middle()
{
	struct node* temp;
	int data;
	temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data: "<<endl;
	cin>>data;
	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}else{
		int pos;
		struct node* p;
		p = head;
		cout<<"Enter the position:"<<endl;
		cin>>pos;
		for(int i = 2; i<pos; i++){
			p = p->next;
		}
		temp->next = p->next;
        temp->prev = p;
		p->next = temp;
        temp->next->prev = temp;
	}
	
}

void insert_end()
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
        temp->prev = p;
        temp->next = NULL;
	}
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
			cout<<p->data<<"<->";
			p = p->next;
		}
	}
}
void reverse_list()
{
	struct node* p;
	p = head;
	if(p == NULL)
	{
		cout<<"List is Empty!"<<endl;
	}
	else
	{
		while(p->next != NULL)
		{
			p = p->next;
		}
        while(p->prev != NULL)
        {
            cout << p->data << " ";
            p = p->prev;
        }
	}
}

int main()
{
	int ch;
	while(1)
	{
		
	cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Print the List\n5:Reverse the List"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert_begin();
			break;
		case 2:
			insert_middle();
			break;
		case 3:
			insert_end();
			break;
			
		case 4:
			print_list();
			break;
		case 5:
            reverse_list();
            break;
	}		
	}	
}