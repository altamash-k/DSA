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

struct node *removeNthNode(struct node *head)
{
    struct node *slow, *fast;

    slow = head;
    fast = head;
    int n;
    cout << "Enter n: ";
    cin >> n;
    if(head->next == NULL)
        return NULL;

    while(n > 0)
    {
        fast = fast->next;
        n--;
    }

    if(fast == NULL)
        return head->next;

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
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
		
        cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Remove Nth Node\n"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                print_list();
                break;
            case 3:
                removeNthNode(head);
                break;
            
        }		
	}	
}