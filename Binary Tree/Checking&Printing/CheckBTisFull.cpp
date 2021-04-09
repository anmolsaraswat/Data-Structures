#include<bits/stdc++.h>
using namespace std;

bool isC = true;
int d = 0;
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void isFull(Node *root, int level)
{
    if(!root)
        return;
    if((root->left && root->right) || (!root->left && !root->right))
    {
        isFull(root->left, level+1);
        isFull(root->right, level+1);
    }
    else
    {
        isC = false;
    }
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    isFull(root, 0);
    if(isC)
        cout << "The tree is Full !!";
    else
        cout << "The tree is not Full.";
    return 0;
}
