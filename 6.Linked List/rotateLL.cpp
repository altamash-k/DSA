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
	int length = 0;
	while(temp != NULL)
	{
		++length;
		temp = temp->next;
	}

	return length;
}

void rotateByK()
{
    int len = length();
    int k;
    cout << "Enter value of k: ";
    cin >> k;

    if(k > len)
        k = k % len;
    
    for(int i = 0; i < k; i++)
    {
        struct node *temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        struct node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
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
		
	cout<<"\nChoose the operations:\n1: Insert a Node\n2: Print the List\n3: Rotate the List\n"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			print_list();
			break;
		case 3:
			rotateByK();
			break;
		
	}		
	}	
}