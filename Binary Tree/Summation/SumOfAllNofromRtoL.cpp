#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void calculate(Node *root, int &total, int val)
{
    if(!root)
        return;
    val = 10*val + root->data;
    if(root->left==NULL && root->right==NULL)
    {
        total = total + val;
        return;
    }
    calculate(root->left, total, val);
    calculate(root->right, total, val);

}

int main()
{
    struct Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->right = new Node(4);
    int tsum = 0;
    int val = 0;
    calculate(root, tsum, val);
    cout << "Sum of all the numbers formed by path from root to leaf is " << tsum;
    return 0;
}
