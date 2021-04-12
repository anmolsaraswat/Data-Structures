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

void print(vector<int> &v)
{
    for(int i =0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void printPath(Node *root, int val, vector<int> &v)
{
    if(root == NULL)
        return;
    v.push_back(root->data);
    if(root->left == NULL && root->right == NULL && root->data == val)
    {
        print(v);
    }
    printPath(root->left, val, v);
    printPath(root->right, val, v);

    v.pop_back();
}


int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    vector<int> v;
    printPath(root, 10, v);
    return 0;
}
