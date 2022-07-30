/*
    floor is the value which is just lesser than or equal to the key given
    E.g: 7's floor will be 6 as it is just lesser than 7 and 7 itself is not present in BST
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

node *findLastRight(struct node *root)
{
    if(root->right == NULL)
        return root;
    return findLastRight(root->right);
}

node *helper(struct node *root)
{
    if(root->left == NULL)
        return root->right;
    else if(root->right == NULL)
        return root->left;
    node *rightChild = root->right;
    node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

node *deleteNode(struct node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return helper(root);
    
    struct node *dummy = root;
    while(root != NULL)
    {
        if(root->data > key)
        {
            if(root->left != NULL && root->left->data == key)
                root->left = helper(root->left);
            else
                root = root->left;
        }
        else
        {
            if(root->right != NULL && root->right->data == key)
                root->right = helper(root->right);
            else
                root = root->right;
        }
    }

    return dummy;
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {

    struct node * root = newNode(10);
    root -> left = newNode(5);
    root -> left -> left = newNode(2);
    root -> left -> right = newNode(6);

    root -> right = newNode(15);

    int key;
    cout << "Enter key: ";
    cin >> key;
    cout << "Before Deleting" << endl;
    inorder(root);

    deleteNode(root, key);

    cout << "\nAfter Deleting" << endl;
    inorder(root);

    return 0;
}