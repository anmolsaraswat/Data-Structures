#include<bits/stdc++.h>
using namespace std;

int i = 0 ;

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool check(Node *root, int arr[], int len)
{
    if(!root || i == len)
        return false;
    if(root->left == NULL && root->right == NULL)
    {
        if((root->data == arr[i]) && (i == len-1))
            return true;
        return false;
    }
    if(root->data == arr[i++])
        return ((i < len) && (root->data == arr[i]) && (check(root->left, arr, len) || check(root->right, arr, len)));
}

int main()
{
    Node *root = new Node(5);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);

    int arr[] = { 5, 2, 4, 8, 7};
    int len = sizeof(arr)/ sizeof(arr[0]);
    if(check(root, arr, len))
        cout << "The given pattern exits.";
    else
        cout << "The given pattern does not exist.";

    return 0;
}
