#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next,*random;
	Node(int x)
	{
		data = x;
		next = random = NULL;
	}
};

void print(Node *head)
{
	Node *ptr = head;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *head)
{
    if (head == NULL) {
        return NULL;
    }

	Node* ptr = head;
    while(ptr != NULL)
    {
        Node* newNode = new Node(ptr->data);
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }

    ptr = head;
    while(ptr != NULL)
    {
        if(ptr->random == NULL)
            ptr->next->random = NULL;
        else
            ptr->next->random = ptr->random->next;
        ptr = ptr->next->next;
    }

    Node* oldptr = head;
    Node* newptr = head->next;
    Node* newhead = head->next;

    while(oldptr != NULL)
    {
        oldptr->next = oldptr->next->next;
        if(newptr->next == NULL)
            newptr->next = NULL;
        else
            newptr->next = newptr->next->next;
        
        oldptr = oldptr->next;
        newptr = newptr->next;
    }

    return newhead;
}

// Driver code
int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	// 1's random points to 3
	head->random = head->next->next;

	// 2's random points to 1
	head->next->random = head;

	// 3's and 4's random points to 5
	head->next->next->random =
					head->next->next->next->next;
	head->next->next->next->random =
					head->next->next->next->next;

	// 5's random points to 2
	head->next->next->next->next->random =
									head->next;

	cout << "Original list : \n";
	print(head);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(head);
	print(cloned_list);

	return 0;
}
