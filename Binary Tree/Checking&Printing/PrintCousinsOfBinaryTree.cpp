#include<bits/stdc++.h>
using namespace std;

int l = 0;
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void getLevel(Node *root, int val, int level)
{
    if(!root)
        return;
    if(root->data == val)
    {
        l = level;
        return;
    }
    getLevel(root->left, val, level+1);
    getLevel(root->right, val, level+1);
}

void printSibling(Node *root, int level, int val, int curr)
{
    if(!root)
        return;
    if(curr == level-1)
    {
        if(root->left && root->left->data == val)
            return;
        if(root->right && root->right->data == val)
            return;
        if(root->left)
            cout << root->left->data << " ";
        if(root->right)
            cout << root->right->data << " ";
    }
    printSibling(root->left, level, val, curr+1);
    printSibling(root->right, level, val, curr+1);

}

void printSibling(Node *root, int val)
{
    getLevel(root, val, 1);
    printSibling(root, l, val, 1);
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

    int val = 5;
    printSibling(root, val);
    return 0;
}
