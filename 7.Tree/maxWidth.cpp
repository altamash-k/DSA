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

int maxWidth(node *root)
{
    if(!root)
        return 0;
    int ans = 0;
    queue<pair<node *, int>> q;
    q.push({
        root, 0
    });

    while(!q.empty())
    {
        int size = q.size();
        int currMin = q.front().second;
        int left, right;
        for(int i = 0; i < size; i++)
        {
            int currId = q.front().second - currMin;
            node *temp = q.front().first;
            q.pop();

            if(i == 0)
                left = currId;
            if(i == size-1)
                right = currId;
            if(temp->left)
            {
                q.push(
                    {
                        temp->left, 
                        currId * 2 + 1
                    }
                );
            }
            if(temp->right)
            {
                q.push(
                    {
                        temp->right, 
                        currId * 2 + 2
                    }
                );
            }
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    struct node *root = new node(1);

    root->left = new node(3);
    root->left->left = new node(5);
    root->left->left->left = new node(7);

    root->right = new node(2);
    root->right->right = new node(4);
    root->right->right->right = new node(6);

    cout << "Max Width: ";
    cout << maxWidth(root);

    return 0;
}