#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

void reorder(node * root) {
    if(root == NULL)
        return;
    int child = 0;
    if(root->left)
        child += root->left->data;
    if(root->right)
        child += root->right->data;

    if(child < root->data) // if root's val is grreater than child
    {
        if(root->left)
            root->left->data = root->data; // make its left data as root ka data
        if(root->right)
            root->right->data = root->data; // make its right data as root ka data
    }

    reorder(root->left);
    reorder(root->right);

    int tot = 0;
    if(root->left)
        tot += root->left->data;
    if(root->right)
        tot += root->right->data;
    if(root->left || root->right)
        root->data = tot;
}

void changeTree(node * root) {
    reorder(root);
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

    struct node * root = newNode(2);
    root -> left = newNode(35);
    root -> left -> left = newNode(2);
    root -> left -> right = newNode(3);
    root -> right = newNode(10);
    root -> right -> left = newNode(5);
    root -> right -> right = newNode(2);

    cout << "Inorder traversal of the constructed tree is" << endl; 
    inOrder(root); 

    cout << endl;
    changeTree(root);

    cout << "Inorder traversal of the children sum tree is" << endl; 
    inOrder(root); 

    return 0;
}