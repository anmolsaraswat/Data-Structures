#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;

    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

void checkPair(struct Node *root, int *rootVal)
{
    if (root == NULL)
        return;
    if( (root->left) && (root->right) && (root->left->data + root->right->data == *rootVal))
        cout << root->left->data << " " << root->right->data << endl;
    checkPair(root->left, rootVal);
    checkPair(root->right, rootVal);


}

int main()
{
    int rootVal = 5;
    struct Node *root = new Node(5);
    root->right = new Node(3);

    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);

    checkPair(root, &rootVal);
    return 0;
}
