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

bool getPath(node *root, vector<int> &arr, int x)
{
    if(!root)
        return false;
    
    arr.push_back(root->data);

    if(root->data == x)
        return true;
    
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
    
    arr.pop_back();
    return false;
}

vector<int> path(node *A, int val)
{
    vector<int> arr;
    if(A == NULL)
        return arr;
    getPath(A, arr, val);
    return arr;
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

    int val;
    cout << "Enter Node val: ";
    cin >> val;

    cout << "Root to Node path: ";
    vector<int> res = path(root, val);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}