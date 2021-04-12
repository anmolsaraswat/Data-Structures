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

void printArray(int ints[], int len, int f)
{
    int i;

    if(f == 0)
    {
        for( i=len-1; i>=0; i--)
        {
            cout << ints[i];
        }
    }
    else if(f ==1)
    {
        for( i =0; i<len; i++)
        {
            for(i = 0; i<len; i++)
            {
                cout << ints[i];
            }
        }
    }
}

int height (Node *root, int &ans, Node *(&k), int &lh, int &rh, int &f)
{
    if (!root)
        return 0;
    int left_height = height(root->left, ans, k, lh, rh, f);
    int right_height = height(root->right, ans, k, lh, rh, f);

    if(ans < 1+left_height + right_height)
    {
        ans = 1+left_height + right_height;

        k = root;
        lh = left_height;
        rh = right_height;
    }
    return 1+max(left_height, right_height);
}

void printPathsRecur (Node *node, int path[], int pathLen, int max, int& f)
{
    if(node == NULL)
        return;

    path[pathLen++] = node->data;

    if(node->left == NULL && node->right == NULL)
    {
        if(pathLen == max && (f ==0 || f==1))
        {
            printArray(path, pathLen, f);
            f =2;
        }
    }
    else
    {
        printPathsRecur(node->left, path, pathLen, max, f);
        printPathsRecur(node->right, path, pathLen, max, f);
    }
}

void diameter(Node *root)
{
    if(root == NULL)
        return;

    int ans = INT_MIN, lh = 0, rh = 0;
    int f = 0;
    Node *k;

    int heigh_of_tree = height(root, ans, k, lh, rh, f);

    int lPath[100], pathlen = 0;
    printPathsRecur(k->left, lPath, pathlen, lh, f);
    cout << k->data;
    int rPath[100];
    f = 1;
    printPathsRecur(k->right, rPath, pathlen, rh, f);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->left->right = new Node(8);
    root->left->left->right->left = new Node(9);

    diameter(root);
    return 0;
}
