#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* loop;
int pos;

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

void create_loop()
{
    cout << "Enter Position where loop is terminated: ";
    cin >> pos;
	struct node* end;
    loop = head;
	end = head;
    for(int i = 0; i < pos; i++) {
        loop = loop -> next;
    }
    while (end->next != NULL)
    {
        end = end -> next;
    }
    end -> next = loop;
    
}

void detect_loop() 
{
    struct node *slow, *fast;
    slow = fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cout << "Loop Detected" << endl;
			return;
        }
    }
    cout << "Loop not detected" << endl;

}

int startingPoint()
{
	struct node *slow, *fast;
    slow = fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
			while(slow != fast)
			{
				fast = head;
				fast = fast->next;
				slow = slow->next;
			}
			return slow->data;
		}
    }
}

void print_list()
{
	struct node* p;
	struct node* tail;
	while (tail != NULL)
	{
		tail = tail-> next;
	}
	
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
		
		cout<<"\nChoose the operations:\n1:Insert at Beginning\n2:Insert at Middle\n3:Insert at End\n4:Print the List\n5: Create Loop\n6: Detect Loop\n7: Starting Point\n"<<endl;
		cin>>ch;
		switch(ch)
		{
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
				create_loop();
				break;
			case 6:
				detect_loop();
				break;
			case 7:
				cout << "Loop is at element: " << startingPoint();
				break;
			default:
				break;
		}		
	}	
}