#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool balanced(struct node *root, int *height)
{
    if(root == NULL)
        return true;
    int lh = 0, rh = 0;
    if(balanced(root->left, &lh) == false)
        return false;
    if(balanced(root->right, &rh) == false)
        return false;
    *height = max(lh,rh) + 1;
    if(abs(lh-rh) <= 1)
        return true;
    else
        return false;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);  
    root->right->right = new node(5);  

    int height = 0;
    if(balanced(root, &height) == true)
        cout << "Balanced tree";
    else
        cout << "Unbalanced tree";

    return 0;
}