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

node *lca(node *root, int p, int q)
{
    if(root == NULL)
        return NULL;
    int curr = root->data;
    if(curr < p && curr < q)
        return lca(root->right, p, q);
    if(curr > p && curr > q)
        return lca(root->left, p, q);

    return root;
}

int main() {
    node * root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->left->right->left = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(18);

    cout << "LCA(3, 6) = " << lca(root, 3, 6)->data;
    cout << "\nLCA(10, 18) = " << lca(root, 10, 18)->data;
    cout << "\nLCA(5, 6) = " << lca(root, 5, 6)->data;
    cout << "\nLCA(8, 18) = " << lca(root, 8, 18)->data;
    return 0;
}