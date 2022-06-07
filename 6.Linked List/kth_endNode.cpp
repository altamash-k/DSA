#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin()
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
		temp->next = head;
		head = temp;
	}
	
}

void insert_middle()
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
		int pos;
		struct node* p;
		p = head;
		cout<<"Enter the position:"<<endl;
		cin>>pos;
		for(int i = 2; i<pos; i++){
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
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
	}
}

void kthNode_end()
{
    struct node* pTemp;
    struct node* kthNode;
    pTemp = head;
    kthNode = head;
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    for(int i = 0; i < k-1; i++) {
        pTemp = pTemp->next;
    }
    while (pTemp->next != NULL)
    {
        /* code */
        pTemp = pTemp->next;
        kthNode = kthNode -> next;
    }
    cout << "Answer is: " << kthNode->data;
    
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
		
	cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Print the List\n5: kth Node"<<endl;
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
			kthNode_end();
			break;
		
	}		
	}	
}