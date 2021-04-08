//Remove all nodes which don’t lie in any path with sum>= k
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;

    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

int max(int l, int r) {return (l > r ? l : r);}

void print(struct Node *root)
{
    if(!root)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

struct Node *pruneUtil(struct Node *root, int k, int *sum)
{
    if(!root)
        return NULL;

    int lsum = *sum + (root->data);
    int rsum = lsum;

    root->left = pruneUtil(root->left, k, &lsum);
    root->right = pruneUtil(root->right, k, &rsum);

    *sum = max(lsum, rsum);

    if(*sum < k)
    {
        free(root);
        root = NULL;
    }
    return root;
};

struct Node *prune(struct Node *root, int k)
{
    int sum = 0;
    return pruneUtil(root, k, &sum);
};

int main()
{
    int k = 45;
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);

    cout << "Tree before Truncation";
    print(root);

    root = prune(root, k);

    cout << endl << "Tree after truncation ";
    print(root);

    return 0;
}
