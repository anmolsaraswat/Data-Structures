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

int height(Node *root, int &ans)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left, ans);
    int rh = height(root->right, ans);
    ans = max(ans, 1+lh+rh);
    return 1+max(lh, rh);
}

int diameter(Node *root)
{
    if(root == NULL)
        return 0;
    int ans = INT_MIN;
    height(root, ans);
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter is : " << diameter(root);
    return 0;
}
