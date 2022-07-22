#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertBST(node *root, int val)
{
    if(root == NULL)
        return new node(val);
    if(val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else 
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

node *search(struct node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(key == root->data)
        return root;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

node *inorderSucc(struct node *root)
{
    node *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    
    return curr;
}

node *deleteInBST(struct node *root, int key)
{
    if(key < root->data)
        root->left = deleteInBST(root->left, key);
    else if(key > root->data)
        root->right = deleteInBST(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;  
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    /*     5
          /  \
         1    7
          \
           3
          /  \
         2    4
    */

    cout << "Inorder: ";
    inorder(root);

    if(search(root, 5) == NULL)
        cout << "\nKey does not exist";
    else
        cout << "\nKey exist";

    cout << endl;
    root = deleteInBST(root, 3);
    inorder(root);

    return 0;
}