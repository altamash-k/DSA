#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

void inorder(node *root, int &k, int &res)
{
    if(root == NULL)
        return;
    
    inorder(root->left, k, res);
    k--;
    if(k == 0)
    {
        res = root->data;
        return;
    }

    inorder(root->right, k, res);
}

int kthSmallest(node *root, int k)
{
    int res = 0;
    inorder(root, k, res);
    return res;
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

int main() {

    struct node * root = newNode(5);
    root -> left = newNode(3);
    root -> left -> left = newNode(2);
    root -> left -> right = newNode(4);
    root -> left -> left->left = newNode(1);

    root -> right = newNode(6);
    // root -> right -> left = newNode(16);

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Kth smallest element is: "  << kthSmallest(root, k);

    return 0;
}