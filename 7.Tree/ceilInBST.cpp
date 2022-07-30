#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

int ceil(struct node *root, int key)
{
    int ceil = -1;
    while(root)
    {
        if(key == root->data)
        {
            ceil = root->data;
            return ceil;
        }
        else if(key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
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

    cout << ceil(root, key);

    return 0;
}