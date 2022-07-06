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

void topView(struct node *root)
{
    vector<int> ans;
    if(root == NULL)
        return;
    
    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        node* curr = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end())
            mp[line] = curr->data;
        
        if(curr->left != NULL)
            q.push({curr->left, line-1});
        if(curr->right != NULL)
            q.push({curr->right, line+1});
    }

    for(auto it:mp)
        ans.push_back(it.second);
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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

    cout << "Top View: ";
    topView(root);


    return 0;
}