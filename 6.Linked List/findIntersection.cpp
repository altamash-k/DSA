#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

void insert_l1()
{
	struct node* temp1;
	int data1;
	temp1 = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data1"<<endl;
	cin>>data1;
	temp1->data = data1;
	temp1->next = NULL;
	if(head1 == NULL){
		head1 = temp1;
	}else{
		struct node* p;
		p = head1;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp1;
	}
}
void insert_l2()
{
	struct node* temp2;
	int data2;
	temp2 = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the Data2"<<endl;
	cin>>data2;
	temp2->data = data2;
	temp2->next = NULL;
	if(head2 == NULL){
		head2 = temp2;
	}else{
		struct node* q;
		q = head2;
		while(q->next != NULL){
			q = q->next;
		}
		q->next = temp2;
	}
}

int length1()
{
    struct node *temp1 = head1;
    int l = 0;
    while (temp1 != NULL)
    {
        l++;
        temp1 = temp1->next;
    }
    return l;
}
int length2()
{
    struct node *temp2 = head2;
    int l = 0;
    while (temp2 != NULL)
    {
        l++;
        temp2 = temp2->next;
    }
    return l;
}

int intersection()
{

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
			cout<<p->data<<"->";
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
			cout<<q->data<<"->";
			q = q->next;
		}
	}
}

int main()
{
    cout<<"\nChoose the operations:\n1: Insert L1\n2: Insert L2\n3: Print List 1\n4: Print List 2\n5: Length of L1\n6: Length of L2\n"<<endl;

	int ch;
	while(1)
	{		
	cout << "\nEnter a choice: ";
    cin>>ch;
	switch(ch){
		case 1:
			insert_l1();
			break;
		case 2:
			insert_l1();
			break;
		case 3:
			print_list_l1();
			break;
		case 4:
			print_list_l2();
			break;
		case 5:
			cout << length1();
			break;
		case 6:
			cout << length2();
			break;
		default:
            exit(0);
            break;
	}		
	}	
}