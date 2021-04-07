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

void printGivenLevel(Node *root, int level, int ltr)
{
    if (!root)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1)
    {
        if(ltr)
        {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else
        {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}

int height(Node *root)
{
    if(!root)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheigh = height(root->right);

        if(lheight > rheigh)
            return (lheight + 1);
        else
            return (rheigh + 1);

    }
}

void printSpiral(Node *root)
{
    int h = height(root);
    int i;

    bool ltr = false;
    for(i=1; i<=h; i++)
    {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "Spiral Order traversal of Binary Tree : ";
    printSpiral(root);

    return 0;
}
