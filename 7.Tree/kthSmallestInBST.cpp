#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

void inorderSmallest(node *root, int &k, int &res)
{
    if(root == NULL)
        return;
    
    inorderSmallest(root->left, k, res);
    k--;
    if(k == 0)
    {
        res = root->data;
        return;
    }

    inorderSmallest(root->right, k, res);
}

void inorderLargest(node *root, int &k, int &res)
{
    if(root == NULL)
        return;
    
    inorderLargest(root->right, k, res);
    k--;
    if(k == 0)
    {
        res = root->data;
        return;
    }

    inorderLargest(root->left, k, res);
}

int kthSmallest(node *root, int k)
{
    int res = 0;
    inorderSmallest(root, k, res);
    return res;
}

int kthLargest(node *root, int k)
{
    int res = 0;
    inorderLargest(root, k, res);
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
    cout << endl;
    cout << "Kth largest element is: "  << kthLargest(root, k);

    return 0;
}