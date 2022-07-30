#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

bool search(struct node *root, int key)
{
    while(root != NULL && root->data != key)
    {
        root = key < root->data ? root->left : root->right;
    }
    if(root == NULL)
        return false;
    else
        return true;
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

    int key;
    cout << "Enter key: ";
    cin >> key;

    if(search(root, key) == true)
        cout << "Key is present";
    else
        cout << "Key is not present";

    return 0;
}