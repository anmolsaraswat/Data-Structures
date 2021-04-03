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

void printRightLeafSum(struct Node *root, int *sum)
{
    if(root == NULL)
        return;
    if(root->right && root->right->left == NULL && root->right->right == NULL)
        *sum = *sum + root->right->data;
    printRightLeafSum(root->left, sum);
    printRightLeafSum(root->right, sum);
}

int main()
{
    int sum = 0;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    printRightLeafSum(root, &sum);

    cout << "The sum of right Leaf is : " << sum;
    return 0;
}
