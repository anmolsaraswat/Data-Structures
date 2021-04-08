#include<bits/stdc++.h>
using namespace std;

bool issum = true;

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void checkProp(struct Node *root)
{
    if(!root)
        return;
    if(root->left && root->right)
    {
        if(root->data != root->left->data + root->right->data)
            issum = false;
    }
    if(root->left && !root->right)
    {
        if(root->data != root->left->data)
            issum = false;
    }
    if(root->right && !root->left)
    {
        if(root->data != root->right->data)
            issum = false;
    }
    checkProp(root->left);
    checkProp(root->right);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    checkProp(root);
    cout << issum;
    return 0;
}
