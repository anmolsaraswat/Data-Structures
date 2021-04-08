#include<bits/stdc++.h>
using namespace std;

bool issum = true;

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int isLeaf(Node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

int isSumTree(struct Node *root)
{
    int ls;
    int rs;
    if(root == NULL || isLeaf(root))
        return 1;
    if(isSumTree(root->left) && isSumTree(root->right))
    {
        if(root->left == NULL)
            ls = 0;
        else if(isLeaf(root->left))
            ls = root->left->data;
        else
            ls = 2*(root->left->data);

        if(root->right == NULL)
            rs = 0;
        else if(isLeaf(root->right))
            rs = root->right->data;
        else
            rs = 2*(root->right->data);

        return(root->data == ls + rs);
    }
    return 0;

}

int main()
{
    struct Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(3);

    if(isSumTree(root))
        cout << "True";
    else
        cout << "False";

    return 0;
}
