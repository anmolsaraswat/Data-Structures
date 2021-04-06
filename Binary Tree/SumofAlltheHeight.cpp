#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x)
    {
        data = x;
        left = right = NULL;
    }
};

int sumOfHeight(struct Node *root)
{
    if(!root)
        return 1;
    int lsum = sumOfHeight(root->left);
    int rsum = sumOfHeight(root->right);
    if (lsum > rsum)
        return (lsum + 1);
    else
        return (rsum + 1);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int height = sumOfHeight(root);
    cout << "Sum of Heights of all the nodes: " << height;

}
