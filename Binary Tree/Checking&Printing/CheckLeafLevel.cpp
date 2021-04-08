#include<bits/stdc++.h>
using namespace std;

bool levelSame = true;


struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void checkUtil(Node *root, int level, int &leafLevel)
{
    if(!root)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        if(leafLevel == 0)
            leafLevel = level;
        else if(leafLevel != level)
            levelSame = false;
    }
    checkUtil(root->left, level+1, leafLevel);
    checkUtil(root->right, level+1, leafLevel);
}

void check(Node *root)
{
    int level=0, leafLevel=0;
    checkUtil(root, level, leafLevel);
}

int main()
{
    struct Node *root = new Node(16);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(3);

    check(root);

    if(levelSame)
    {
        cout << "The leaf nodes are at same level";
    }
    else
    {
        cout << "The leaf nodes are not at the same level";
    }

    return 0;
}
