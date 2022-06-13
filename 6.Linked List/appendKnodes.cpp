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

int length()
{
    struct node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void kappend()
{
    struct node *newHead;
    struct node *newTail;
    struct node *tail = head;

    int l = length();
    int k;
    cout << "Enter value of k: ";
    cin>>k;
    k = k % l; //for k>l
    int count = 1;
    while (tail->next != NULL)
    {   
        if(count == l-k)
            newTail = tail;
        if(count == l-k+1)
            newHead = tail;
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail ->next = head;
    head = newHead;
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
			cout<<p->data<<"->";
			p = p->next;
		}
	}
}

int main()
{
    cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Append last K nodes\n"<<endl;

	int ch;
	while(1)
	{		
	cout << "\nEnter a choice: ";
    cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			print_list();
			break;
		case 3:
			kappend();
			break;
		default:
            exit(0);
            break;
	}		
	}	
}