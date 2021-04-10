#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool isFullBinaryTree(Node *root)
{
    if(!root)
        return true;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if(node->left == NULL && node->right == NULL)
            continue;
        if(node->left == NULL || node->right == NULL)
            return false;

        q.push(node->left);
        q.push(node->right);
    }
    return true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if(isFullBinaryTree(root))
        cout << "True";
    else
        cout << "No";

    return 0;
}
