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

struct node * merge_lists()
{
	struct node *p1 = head1;
	struct node *p2 = head2;
	struct node *dummyNode;
	dummyNode = (struct node*)malloc(sizeof(struct node));
	struct node *p3 = dummyNode;
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data < p2->data)
		{
			p3->next = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}

	while (p1 != NULL)
	{
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	while (p2 != NULL)
	{
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	return dummyNode->next;

	//To print the merged list choose operation 3: Print list 1
}

// struct node *merge_lists()
// {
// 	struct node *l1 = head1;
// 	struct node *l2 = head2;
// 	struct node *res = l1;

// 	if(l1 == NULL)
// 		return l2;
// 	if(l2 == NULL)
// 		return l1;

// 	while(l1 != NULL && l2 != NULL)
// 	{
// 		struct node *temp = NULL;
// 		while(l1 != NULL && l1->data < l2->data)
// 		{
// 			temp = l1;
// 			l1 = l1->next;
// 		}

// 		temp->next = l2;
// 		swap(l1, l2);
// 	}

// 	return res;
// }

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