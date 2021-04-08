#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x)
    {
        data = x;
        left = right = NULL;
    }
};


Node *mergeBT(Node *a, Node *b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    a->data += b->data;
    a->left = mergeBT(a->left, b->left);
    a->right = mergeBT(a->right, b->right);
    return a;
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
    struct Node *r1 = new Node(2);
    r1->left = new Node(1);
    r1->left->left = new Node(5);
    r1->right = new Node(4);

    struct Node *r2 = new Node(3);
    r2->left = new Node(6);
    r2->left->right = new Node(2);
    r2->right = new Node(1);
    r2->right->right = new Node(7);

    struct Node *m = mergeBT(r1, r2);
    traverse(m);

    return 0;
}
