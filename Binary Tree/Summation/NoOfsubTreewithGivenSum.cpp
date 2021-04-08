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

int subTreeSum(Node *root, int sum, int &val)
{
    if(!root)
        return 0;
    int subSum = root->data + subTreeSum(root->left, sum, val) + subTreeSum(root->right, sum, val);
    if(subSum == sum)
    {
        val++;
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);
    int x = 7;
    int c = 0;
    subTreeSum(root, x, c);
    cout << "The no of subtrees are : " << c;
    return 0;
}
