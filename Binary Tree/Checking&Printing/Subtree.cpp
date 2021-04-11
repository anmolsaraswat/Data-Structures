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


bool isIdentical(Node *a, Node *b)
{
    if(a == NULL && b == NULL)
        return true;
    if(a == NULL || b == NULL)
        return false;
    return ((a->data == b->data) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right));

}

bool isSubset(Node *a, Node *b)
{
    if(b == NULL)
        return true;
    if(a == NULL)
        return false;
    return (isIdentical(a->left, b) || isIdentical(a->right, b));
}

int main()
{
    struct Node *root1 = new Node(21);
    root1->left = new Node(10);
    root1->left->right = new Node(6);
    root1->left->left = new Node(4);
    root1->left->left->right = new Node(30);
    root1->right = new Node(3);
    root1->right->right = new Node(3);


    struct Node *root2 = new Node(10);
    root2->right = new Node(6);
    root2->left = new Node(4);
    root2->left->right = new Node(30);

    if(isSubset(root1, root2))
        cout << "The tree is a subset.";
    else
        cout << "The tree is not a subset.";

    return 0;
}
