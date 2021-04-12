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

bool isBalancedUtil(Node *root, int &maxh, int &minh)
{
    if(root == NULL)
    {
        maxh = minh = 0;
        return true;
    }

    int lmxh, lmnh;
    int rmxh, rmnh;

    if(isBalancedUtil(root->left ,lmxh, lmnh) == false)
        return false;
    if(isBalancedUtil(root->right, rmxh, rmnh) == false)
        return false;

    maxh = max(lmxh, rmxh) + 1;
    minh = min(lmnh, rmnh) + 1;

    if(maxh <= 2*minh)
        return true;

    return false;

}

bool isBalanced(Node *root)
{
    int maxh, minh;
    return isBalancedUtil(root, maxh, minh);
}

int main()
{
    Node * root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(100);
    root->right->left = new Node(50);
    root->right->right = new Node(150);
    root->right->left->left = new Node(40);
    isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";
    return 0;
}
