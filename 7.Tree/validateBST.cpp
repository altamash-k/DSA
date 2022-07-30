#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

int isBSTUtil(node* node, int min, int max);
 
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

int main() {

    struct node * root = newNode(15);
    root -> left = newNode(12);
    root -> left -> left = newNode(9);
    root -> left -> right = newNode(14);

    root -> right = newNode(18);
    root -> right -> left = newNode(16);

    if(isBST(root))
        cout << "Valid Binary Tree";
    else
        cout << "Invalid Binary Tree";

    return 0;
}