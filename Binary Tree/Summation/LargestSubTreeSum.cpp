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
int findLargestSubtreeSum(Node *root, int& ans)
{
    if(root == NULL)
        return 0;
    int currSum = root->data + findLargestSubtreeSum(root->left, ans) + findLargestSubtreeSum(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
    int ans = INT_MIN;

    int temp = findLargestSubtreeSum(root, ans);
    cout << ans;
    return 0;
}
