// Replace each node in binary tree with the sum of its inorder predecessor and successor

#include<bits/stdc++.h>
using namespace std;

int i =1;
struct Node {
    int data;
    struct Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &v)
{
    if(!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void fun(Node *root, vector<int> &v)
{
    if(!root)
        return;
    fun(root->left, v);
    root->data = v[i-1] + v[i+1];
    i++;
    fun(root->right, v);
}

void traverse(Node *root)
{
    if(!root)
        return;
    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
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

    std::vector<int> v;
    v.push_back(0);
    inorder(root, v);
    v.push_back(0);
    fun(root, v);
    traverse(root);
}
