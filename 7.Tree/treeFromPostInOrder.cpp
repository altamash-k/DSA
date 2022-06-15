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

node *buildTree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if(start > end)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;
    node *newnode = new node(curr);
    if(start == end)
        return newnode;

    int pos = search(inorder, start, end, curr);
    newnode->right = buildTree(postorder, inorder, pos+1, end);
    newnode->left = buildTree(postorder, inorder, start, pos-1);
    
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
    int n_post;
    cout << "No of elements in postorder: ";
    cin >> n_post;
    int postorder[n_post];
    cout << "Enter elements for postorder: ";
    for(int i = 0; i < n_post; i++)
        cin>>postorder[i];

    int n_in;
    cout << "No of elements in inorder: ";
    cin >> n_in;
    int inorder[n_in];
    cout << "Enter elements for inorder: ";
    for(int i = 0; i < n_in; i++)
        cin>>inorder[i];

    node *root = buildTree(postorder, inorder, 0, n_in-1);
    inorderPrint(root);
}