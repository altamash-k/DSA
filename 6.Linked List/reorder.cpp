/*
    Given head of linked-list, reorder list alternating outside in
    Ex. head = [1,2,3,4] -> [1,4,2,3], head = [1,2,3,4,5] -> [1,5,2,4,3]

    Find middle node, split in half, reverse 2nd half of list, merge

    Time: O(n)
    Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *reverse(struct node *head)
{
    struct node *prev, *curr, *next;

    prev = NULL;
    curr = head;
    next = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void merge(struct node *l1, struct node *l2)
{
    while(l1 != NULL)
    {
        struct node *p1 = l1->next;
        struct node *p2 = l2->next;

        l1->next = l2;
        if(p1 == NULL)
            break;
        
        l2->next = p1;
        l1 = p1;
        l2 = p2;
    }
}

void reorder(struct node *head)
{
    if(head->next == NULL)
        return;
    
    struct node *prev = NULL;
    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    struct node *l1 = head;
    struct node *l2 = reverse(slow);

    merge(l1, l2);
}

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
		
        cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Reorder the List\n"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                print_list();
                break;
            case 3:
                reorder(head);
                break;
            
        }		
	}	
}