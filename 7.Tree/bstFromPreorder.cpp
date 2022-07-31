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

node *build(vector<int>& preorder, int &i, int bound)
{
    if(i == preorder.size() || preorder[i] > bound)
        return NULL;
    node *root = new node(preorder[i++]);
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);

    return root;
}

node *buildTree(vector<int>& preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

void inorder(node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    int n_pre;
    cout << "No of elements in preorder: ";
    cin >> n_pre;

    vector<int> preorder;
    cout << "Enter elements for preorder: ";
    for(int i = 0; i < n_pre; i++)
    {
        int data;
        cin >> data;
        preorder.push_back(data);
    }

    node *root = buildTree(preorder);
    inorder(root);
}