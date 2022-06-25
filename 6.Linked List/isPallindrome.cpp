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

struct node *reverse(struct node *ptr)
{
    struct node *prev, *next;
    prev = NULL;
    next = NULL;
    while(ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    return prev;
}

bool isPallindrome()
{
    if(head == NULL || head->next == NULL)
        return true;

    //to find middle
    struct node *slow = head;
    struct node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // reverse after middle node
    slow->next = reverse(slow->next);
    slow = slow->next;
    node *dummy = head;
    while(slow != NULL)
    {
        if(dummy->data != slow->data)
            return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
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
		
	cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Is Pallindrome?\n"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			print_list();
			break;
		case 3:
			if(isPallindrome() == true)
                cout << "Pallindrome";
            else
                cout << "Not A Pallindrome";
		
	}		
	}	
}