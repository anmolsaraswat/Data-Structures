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

void printLeftLeafSum(struct Node *root, int *sum)
{
    if(root == NULL)
        return;
    if(root->left && root->left->left == NULL && root->left->right == NULL)
        *sum = *sum + root->left->data;
    printLeftLeafSum(root->left, sum);
    printLeftLeafSum(root->right, sum);
}

int main()
{
    int sum = 0;
    struct Node *root = new Node(9);
    root->left = new Node(8);
    root->left->left = new Node(5);
    root->left->right = new Node(2);
    root->right = new Node(6);
    root->right->left = new Node(1);

    printLeftLeafSum(root, &sum);

    cout << "The sum of left Leaf is : " << sum;
    return 0;
}
