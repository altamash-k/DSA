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

void makeCycle()
{
    struct node *temp = head;
    struct node *startnode;
    int count = 1;
    int pos;
    cout<<"Enter position to make cycle: ";
    cin>>pos;
    while (temp->next != NULL)
    {
        if(count == pos)
            startnode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detectCycle()
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast == slow)
            return true;
    }
    return false;
    
}

void removeCycle()
{
    struct node *slow = head;
    struct node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
		
	cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Make Cycle\n4: Detect Cycle\n5: Remove Cycle\n"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			print_list();
			break;
		case 3:
			makeCycle();
			break;
		case 4:
			cout << detectCycle();
			break;
		case 5:
			removeCycle();
			break;
		
	}		
	}	
}