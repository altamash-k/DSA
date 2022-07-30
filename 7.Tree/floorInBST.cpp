/*
    floor is the value which is just lesser than or equal to the key given
    E.g: 7's floor will be 6 as it is just lesser than 7 and 7 itself is not present in BST
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left, * right;
};

int floor(struct node *root, int key)
{
    int floor = -1;
    while(root)
    {
        if(key == root->data)
        {
            floor = root->data;
            return floor;
        }
        else if(key > root->data)
        {
            floor = root->data;
            root = root->right;
        } 
        else
        {
            root = root->left;
        }
    }

    return floor;
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}

int main() {

    struct node * root = newNode(10);
    root -> left = newNode(5);
    root -> left -> left = newNode(2);
    root -> left -> right = newNode(6);

    root -> right = newNode(15);

    int key;
    cout << "Enter key: ";
    cin >> key;

    cout << floor(root, key);

    return 0;
}