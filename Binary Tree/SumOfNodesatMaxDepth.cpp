#include<bits/stdc++.h>
using namespace std;

int sum = 0, max_level = INT_MIN;

struct Node {
    int data;
    struct Node *left, *right;
    Node (int x)
    {
        data = x;
        left = right = NULL;
    }
};

void maxSum(Node* root, int level)
{
    if(!root)
        return;
    if(level > max_level)
    {
        sum = root->data;
        max_level = level;
    }
    else if(level == max_level)
    {
        sum = sum + root->data;
    }

    maxSum(root->left, level + 1);
    maxSum(root->right, level + 1);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    maxSum(root, 0);
    cout << sum;
    return 0;
}
