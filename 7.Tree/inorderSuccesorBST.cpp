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

int inorderSuccesor(node *root, int p)
{
    int succ = 0;

    while(root != NULL)
    {
        if(root->data <= p)
            root = root->right;
        else
        {
            succ = root->data;
            root = root->left;
        }
    }

    return succ;
}

int main() {

    struct node * root = newNode(15);
    root -> left = newNode(12);
    root -> left -> left = newNode(9);
    root -> left -> right = newNode(14);

    root -> right = newNode(18);
    root -> right -> left = newNode(16);

    int p;
    cout << "Enter Element: ";
    cin >> p;

    cout << inorderSuccesor(root, p);

    return 0;
}