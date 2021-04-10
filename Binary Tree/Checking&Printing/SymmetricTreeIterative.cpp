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

bool isSym(Node *root)
{
    if(root == NULL)
        return true;
    if(!root->left && !root->right)
        return true;

    queue <Node *>  q;

    q.push(root);
    q.push(root);

    Node *leftNode, *rightNode;

    while(!q.empty())
    {
        leftNode = q.front();
        q.pop();
        rightNode = q.front();
        q.pop();

        if(leftNode->data != rightNode->data)
            return false;
        if(leftNode->left && rightNode->right)
        {
            q.push(leftNode->left);
            q.push(rightNode->right);
        }
        else if(leftNode->left || rightNode->right)
            return false;
        if(leftNode->right && rightNode->left)
        {
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        else if(leftNode->right || rightNode->left)
            return false;
    }
    return true;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    if(isSym(root))
        cout << "The Tree is symmetric.";
    else
        cout << "The tree is not symmetric";
    return 0;
}

