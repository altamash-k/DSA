#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

class Solution {
    node *prev = NULL;
    public:
        void flatten(node *root)
        {
            if(root == NULL)
                return;
            stack<node *> st;
            st.push(root);
            while(!st.empty())
            {
                node *curr = st.top();
                st.pop();

                if(curr->right != NULL) // first push right
                    st.push(curr->right);
                if(curr->left != NULL) // then left
                    st.push(curr->left);
                if(!st.empty()) // make right of curr as top of stack
                    curr->right = st.top();
                curr->left = NULL; // make left of curr as NULL
            }
        }
};

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

int main() {

    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(3);
    root -> left -> right = newNode(4);
    root -> right = newNode(5);
    root -> right -> right = newNode(6);
    root -> right -> right -> left = newNode(7);

    Solution obj;

    obj.flatten(root);
    while(root->right!=NULL)
    {
        cout<<root->data<<"->";
        root=root->right;
    }
    cout<<root->data;
    return 0;
}