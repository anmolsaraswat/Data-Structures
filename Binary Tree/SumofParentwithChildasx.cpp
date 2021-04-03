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

void printsumRoot(struct Node *root, int *sum)
{
    if(root == NULL)
        return;
    if((root->left && root->left->data == 2) || (root->right && root->right->data ==2))
    {
        *sum = *sum + root->data;
    }
    printsumRoot(root->left, sum);
    printsumRoot(root->right, sum);
}

int main()
{
    int sum = 0;
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(2);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    printsumRoot(root, &sum);
    cout << "Sum of roots with 2 as a child : " << sum;
    return 0;
}
