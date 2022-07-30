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

node *insert(struct node *root, int val)
{
    if(root == NULL)
        root = newNode(val);
    node *curr = root;
    while(true)
    {
        if(val >= curr->data)
        {
            if(curr->right != NULL)
                curr = curr->right;
            else
            {
                curr->right = newNode(val);
                break;
            }
        }
        else
        {
            if(curr->left != NULL)
                curr = curr->left;
            else
            {
                curr->left = newNode(val);
                break;
            }
        }
    }

    return root;
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
    cout << "Before Inserting" << endl;
    inorder(root);

    insert(root, key);

    cout << "\nAfter Inserting" << endl;
    inorder(root);

    return 0;
}