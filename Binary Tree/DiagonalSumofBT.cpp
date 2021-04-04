#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

void diagonalSumUtil(struct Node* root, int vd, map<int, int> &diagonalSum)
{
    if(!root)
        return;
    diagonalSum[vd] += root->data;

    diagonalSumUtil(root->left, vd + 1, diagonalSum);
    diagonalSumUtil(root->right, vd, diagonalSum);
}

void diagonalSum(struct Node *root)
{
    map<int, int> diagonalSum;
    diagonalSumUtil(root, 0, diagonalSum);

    map<int, int>::iterator it;
    cout << "Diagonal Sum of a binary tree is : ";

    for(it = diagonalSum.begin(); it!=diagonalSum.end(); ++it)
        cout<< it->second << " ";

}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(9);
    root->left->left->right = new Node(10);
    root->left->right = new Node(6);
    root->left->right->left = new Node(11);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(7);
    root->right->right = new Node(5);

    diagonalSum(root);
    return 0;

}
