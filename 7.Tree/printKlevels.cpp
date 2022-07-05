#include<bits/stdc++.h>
using namespace std;\

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void kLevels(struct node *root, int k)
{
    if(root == NULL || k < 0)
        return;
    if(k == 0)
        cout << root->data << " ";
    kLevels(root->left, k-1);
    kLevels(root->right, k-1);
}

int main()
{
    struct node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    root->right->right = new node(7);

    int k;
    cout << "Enter k: ";
    cin >> k;

    kLevels(root, k);

    return 0;
}