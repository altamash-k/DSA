#include<bits/stdc++.h>
using namespace std;

struct LLNode
{
    int data;
    struct LLNode* right;
    struct LLNode* down;  
};
/* Function to insertAtBeginning ListA node */
void insertAtBeginning(struct LLNode** head, int dataToBeInserted)
{
    struct LLNode* curr = new LLNode;
    curr->data = dataToBeInserted;
    curr->right = NULL;
    curr->down = *head;
    *head = curr; 
}
 
void display(struct LLNode**node)
{
    struct LLNode *temp= *node;
    while(temp!=NULL)
        {
            if(temp->down!=NULL)
            cout<<temp->data<<"->";
            else
            cout<<temp->data;
            
            temp=temp->down; //move to right node
        }

    cout<<endl;
}
 
//Merge sort of ListA and ListB
struct LLNode* MergeSort(struct LLNode* ListA, struct LLNode* ListB )
{
    //Base cases
    if (ListA == NULL)
    {
        return ListB;
    }
    if (ListB == NULL)
    {
        return ListA;
    }
    //compare data of heads and add smaller to root
    struct LLNode* result;
    if (ListA->data < ListB->data)
    {
        result = ListA;
        result->down = MergeSort(ListA->down, ListB);
    }
    else
    {
        result = ListB;
        result->down = MergeSort(ListA, ListB->down);
    }
 
    return result;
}
 
//Function that flattens the given list
struct LLNode* flatten(struct LLNode* root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }
    //Merge right with already flattens
    return MergeSort(root,flatten(root->right) );
}
 
//Main function
int main()
{

    struct LLNode* root = NULL;
 
    insertAtBeginning(&root, 14);
    insertAtBeginning(&root, 8);
    insertAtBeginning(&root, 7);
 
    insertAtBeginning(&(root->right), 6);
    insertAtBeginning(&(root->right), 4);
    
    insertAtBeginning(&(root->right->right), 18);
    insertAtBeginning(&(root->right->right), 13);
    insertAtBeginning(&(root->right->right), 9);
    insertAtBeginning(&(root->right->right->right), 18);
    insertAtBeginning(&(root->right->right->right), 17);
    insertAtBeginning(&(root->right->right->right), 15);
    insertAtBeginning(&(root->right->right->right), 11); 
 
    insertAtBeginning(&(root->right->right->right->right), 16);
   
    root = flatten(root);
    
    cout<<"Flatten List is: " << endl;
    display(&root);
 
    return 0;
}
