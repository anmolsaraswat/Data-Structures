#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
    }
};

int getSum(Node *root);

int getSumAlt(Node *root)
{
    if(!root)
        return 0;

    int sum = root->data;
    if(root->left != NULL)
    {
        sum += getSum(root->left->left);
        sum += getSum(root->left->right);
    }
    if(root->right != NULL)
    {
        sum += getSum(root->right->left);
        sum += getSum(root->right->right);
    }
    return sum;
}

int getSum(Node *root)
{
    if(root == NULL)
        return 0;
    return max(getSumAlt(root), (getSumAlt(root->left) + getSumAlt(root->right)));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);
    root->right->left->right->left = new Node(6);

    cout << (getSum(root));
    return 0;
}
