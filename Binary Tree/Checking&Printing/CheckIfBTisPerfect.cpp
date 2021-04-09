#include<bits/stdc++.h>
using namespace std;


bool isP = true;
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

void isPerfect(Node *root, int level)
{
    if(!root)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        if(d == 0)
        {
            d = level;
        }
        else if( d != level)
        {
            isP = false;
        }
    }
    if((root->left && root->right) || (!root->left && !root->right))
    {
        isPerfect(root->left, level+1);
        isPerfect(root->right, level+1);
    }
    else
    {
        isP = false;
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

    isPerfect(root, 0);
    if(isP)
        cout << "The tree is perfect !!";
    else
        cout << "The tree is not perfect.";
    return 0;
}
