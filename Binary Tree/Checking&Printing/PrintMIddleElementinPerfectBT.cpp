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

void printMUtil(Node *a, Node *b)
{
    if(b == NULL)
        return;
    if(b->left == NULL && b->right == NULL)
    {
        cout << a->data << " ";
        return;
    }
    if(b->left->left)
    {
        printMUtil(a->left, b->left->left);
        printMUtil(a->right, b->left->left);
    }
    else
    {
        printMUtil(a, b->left);
    }
}

void printMiddle(Node *root)
{
    printMUtil(root, root);
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

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    printMiddle(root);
    return 0;
}
