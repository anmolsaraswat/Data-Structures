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

int count(Node *root)
{
    if(!root)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int checkRec(Node *root, int n, bool &res)
{
    if(!root)
        return 0;
    int c = checkRec(root->left, n, res) + 1 + checkRec(root->right, n, res);

    if(c == n-c)
        res = true;
    return c;
}

bool check(Node *root)
{
    int n = count(root);

    bool res = false;
    checkRec(root, n, res);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(4);

    if(check(root))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
