#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

node *lca(node *root, int p, int q)
{
    if(root == NULL || root->data == p || root->data == q)
        return root;
    node *left = lca(root->left, p, q);
    node *right = lca(root->right, p, q);

    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    else
        return root;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << lca(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << lca(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << lca(root, 2, 4)->data;
    return 0;
}