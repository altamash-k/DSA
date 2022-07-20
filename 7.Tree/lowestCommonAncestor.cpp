#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int lca(node *root, int p, int q)
{
    if(root == NULL || root->data == p || root->data == q)
        return root->data;
    int left = lca(root->left, p, q);
    int right = lca(root->right, p, q);

    if(left == NULL)
        return right;
    if(right == NULL)
        return right;
    else
        return root->data;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  int res = lca(root, 4, 5);

  cout << "LCA is: " << res;

  return 0;
}