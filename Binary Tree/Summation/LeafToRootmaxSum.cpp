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

void getTargetLeaf(struct Node *root, int *max_sum_ref, int curr_sum, struct Node **target_leaf_ref)
{
    if(root == NULL)
        return;

    curr_sum += root->data;

    if(root->left == NULL && root->right == NULL)
    {
        if(curr_sum> *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = root;
        }
    }

    getTargetLeaf(root->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf(root->right, max_sum_ref, curr_sum, target_leaf_ref);
}

bool printPath(struct Node *root, struct Node* target_leaf)
{
    if(root == NULL)
        return false;

    if(root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf))
    {
        cout << root->data << " ";
        return true;
    }
    return false;
}

int maxSumPath(struct Node *root)
{
    if(root == NULL)
        return 0;

    struct Node *target_leaf;
    int max_sum = INT_MIN;
    getTargetLeaf(root, &max_sum, 0, &target_leaf);

    printPath(root, target_leaf);

    return max_sum;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    cout << "Following are the nodes on the maximum sum path \n";
    int sum = maxSumPath(root);
    cout << "\nSum of the nodes is " << sum;
    return 0 ;
}
