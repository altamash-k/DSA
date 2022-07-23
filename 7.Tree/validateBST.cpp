#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

bool validateBST(node *root)
{
    stack<node *> st;
    node *prev = NULL;
    while(!st.empty() || root != NULL)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();

        if(prev != NULL && prev->data >= root->data)
            return false;
        
        prev = root;
        root = root->right;

    }

    return true;
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

int main() {

    struct node * root = newNode(15);
    root -> left = newNode(12);
    root -> left -> left = newNode(9);
    root -> left -> right = newNode(14);

    root -> right = newNode(18);
    root -> right -> left = newNode(16);

    bool isValid = validateBST(root);
    if(isValid == true)
        cout << "Valid Binary Tree";
    else
        cout << "Invalid Binary Tree";

    return 0;
}