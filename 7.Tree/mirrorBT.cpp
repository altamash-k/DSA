#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};


void mirror(node *root)
{
    if(!root)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

void inOrder(node* root)  
{ 
    if (root == NULL)  
        return; 
      
    inOrder(root->left); 
    cout << root->data << " "; 
    inOrder(root->right); 
}

int main() {

    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
      
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl; 
    inOrder(root); 
      
    /* Convert tree to its mirror */
    mirror(root);  
      
    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";  
    inOrder(root); 
      
    return 0;  
}