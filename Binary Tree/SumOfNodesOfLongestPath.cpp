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

void sumofLongestPath(Node *root, int sum, int len, int& maxLen, int& maxSum)
{
    if(!root)
    {
        if(maxLen < len)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(maxLen == len && maxSum < sum)
        {
            maxSum = sum;
        }
        return;
    }
    sumofLongestPath(root->left, sum + root->data, len+1, maxLen, maxSum);
    sumofLongestPath(root->right, sum + root->data, len +1, maxLen, maxSum);
}

int printLongestPathSum(struct Node *root)
{
    if(!root)
        return 0;

    int maxSum = INT_MIN, maxLen = 0;

    sumofLongestPath(root, 0, 0 , maxLen, maxSum);

    return maxSum;
}
int main()
{
    struct Node *root = new Node(4);

    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);

    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    cout << "Sum : " << printLongestPathSum(root);
    return 0;
}
