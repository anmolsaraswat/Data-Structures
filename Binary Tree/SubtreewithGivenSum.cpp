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

int subtreesum(Node *root, int sum)
{
    if(!root)
        return 0;
    int currSum = root->data + subtreesum(root->left, sum) + subtreesum(root->right, sum);
    if(currSum == sum)
        cout << "We have a subtree with given sum.";
}

int main()
{
    struct Node *root = new Node(8);
    root->left    = new Node(5);
    root->right   = new Node(4);
    root->left->left = new Node(9);
    root->left->right = new Node(7);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(12);
    root->left->right->right->right = new Node(2);
    root->right->right = new Node(11);
    root->right->right->left = new Node(3);
    int sum = 22;

    subtreesum(root, sum);
}
