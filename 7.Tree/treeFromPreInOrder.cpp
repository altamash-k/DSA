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

int search(int inorder[], int start, int end, int curr)
{
    for(int i = start; i<=end; i++)
    {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node *newnode = new node(curr);
    if(start == end)
        return newnode;

    int pos = search(inorder, start, end, curr);
    newnode->left = buildTree(preorder, inorder, start, pos-1);
    newnode->right = buildTree(preorder, inorder, pos+1, end);

    return newnode;
}

void inorderPrint(node *root)
{
    if(root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{

    int n_pre;
    cout << "No of elements in preorder: ";
    cin >> n_pre;
    int preorder[n_pre];
    cout << "Enter elements for preorder: ";
    for(int i = 0; i < n_pre; i++)
        cin>>preorder[i];

    int n_in;
    cout << "No of elements in inorder: ";
    cin >> n_in;
    int inorder[n_in];
    cout << "Enter elements for inorder: ";
    for(int i = 0; i < n_in; i++)
        cin>>inorder[i];

    node *root = buildTree(preorder, inorder, 0, n_in-1);
    inorderPrint(root);
}