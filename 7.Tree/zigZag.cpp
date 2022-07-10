#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val;
    Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
    vector<vector<int>> res;
    if(root == NULL)
        return res;
    
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            
            int index = (leftToRight) ? i : (size-1-i);

            row[index] = node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        res.push_back(row);
    }

    return res;
}
Node * newNode(int data) {
    Node * node = new Node;
    node -> val = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}
int main() {
    int i, j;
    Node * root = newNode(3);

    root -> left = newNode(9);
    root -> right = newNode(20);

    root -> left -> left = newNode(10);
    root -> left -> right = newNode(12);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);
    
    root -> right -> left->left = newNode(15);
    root -> right -> right->left = newNode(23);
    root -> right -> right->right = newNode(26);
    vector < vector < int >> ans;
    ans = zigzagLevelOrder(root);
    cout << "Zig Zag Traversal of Binary Tree" << endl;
    for (i = 0; i < ans.size(); i++) {
        for (j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
