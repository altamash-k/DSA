#include<bits/stdc++.h>
using namespace std;

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

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int count(struct node *root)
{
    if(root == NULL)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int sum(struct node *root)
{
    if(root == NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

int diameter(struct node *root)
{
    if(root == NULL)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiam = lHeight + rHeight + 1;
    int lDiam = diameter(root->left);
    int rDiam = diameter(root->right);

    return max(currDiam, max(lDiam, rDiam));
}

void sumReplacement(struct node *root)
{
    if(root == NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);
    if(root->left != NULL)
        root->data += root->left->data;
    if(root->right != NULL)
        root->data += root->right->data;
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

    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);

    cout << "\nTotal no of nodes are: ";
    cout << count(root);

    cout << "\nSum of nodes are: ";
    cout << sum(root);

    cout << "\nHeight of the tree is: ";
    cout << height(root);

    cout << "\nDiameter of the tree is: ";
    cout << diameter(root);

    cout << "\nSum Replcament: ";
    sumReplacement(root);
    preorder(root);

    return 0;
}