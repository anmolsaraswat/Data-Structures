#include<bits/stdc++.h>
using namespace std;

int l1 = 0, l2 = 0;
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void checkLevel(Node *root, int a, int b, int level)
{
    if(!root)
        return;
    if(root->data == a)
        l1 = level;
    if(root->data == b)
        l2 = level;
    checkLevel(root->left, a, b, level+1);
    checkLevel(root->right, a, b, level+1);
}

void checkParent(Node *root, int a, int b, Node *p1, Node *p2)
{
    if(!root)
        return;
    if(root->left && root->left->data == a)
        p1 = root;
    if(root->right && root->right->data == a)
        p1 = root;
    if(root->left && root->left->data == b)
        p2 = root;
    if(root->right && root->right->data == b)
        p2 = root;
    checkParent(root->left, a, b, p1, p2);
    checkParent(root->right, a, b, p1, p2);
}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(1);
    root->right->right = new Node(3);

    int a = 5;
    int b = 1;

    checkLevel(root, a, b, 1);

    Node * p1, *p2;
    checkParent(root, a, b, p1, p2);
    if((l1 == l2) && (p1 != p2))
    {
        cout << "These 2 nodes are siblings.";
    }
    else
    {
        cout << "These nodes are not siblings";
    }



    return 0;
}
