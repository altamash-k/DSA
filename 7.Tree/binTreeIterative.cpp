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

vector<int> preorder(struct node *root)
{
    vector<int> pre;
    if(root == NULL)
        return pre;
    
    stack<node *> st;
    st.push(root);

    while(!st.empty())
    {
        struct node *topnode = st.top();
        pre.push_back(topnode->data);
        st.pop();
        if(topnode->right != NULL)
            st.push(topnode->right);
        if(topnode->left != NULL)
            st.push(topnode->left);
    }

    return pre;
}

vector<int> inorder(struct node *root)
{
    vector<int> in;
    stack<node *> st;
    while(true)
    {
        if(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if(st.empty())
                break;

            root = st.top();
            in.push_back(root->data);
            st.pop();
            root = root->right;
        }
    }

    return in;
}

vector<int> postorder(struct node *root)
{
    vector<int> post;
    if(root == NULL)
        return post;
    stack<node *> st1;
    stack<node *> st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL)
            st1.push(root->left);
        if(root->right != NULL)
            st1.push(root->right);
    }

    while(!st2.empty())
    {
        struct node *topVal = st2.top();
        post.push_back(topVal->data);
        st2.pop();
    }

    return post;
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
    vector<int> pre = preorder(root);
    for(int i = 0; i < pre.size(); i++)
        cout << pre[i] << " ";

    cout << endl;
    cout << "Inorder: ";
    vector<int> in = inorder(root);
    for(int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    cout << endl;
    cout << "Postorder: ";
    vector<int> post = postorder(root);
    for(int i = 0; i < post.size(); i++)
        cout << post[i] << " ";

    // cout << endl;
    // cout << "Inorder: ";
    // inorder(root);
    // cout << endl;
    // cout << "Postorder: ";
    // postorder(root);

    return 0;
}