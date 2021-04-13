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

void printVertical(Node *root, map<int, vector<int>> &v, int order)
{
    if(!root)
        return;
    v[order].push_back(root->data);
    printVertical(root->left, v, order-1);
    printVertical(root->right, v, order+1);
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
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    map<int, vector<int>> v;
    printVertical(root, v, 0);

    map<int, vector<int>> :: iterator it;
    for(it = v.begin(); it!=v.end(); ++it)
    {
        for(int i=0; i<it->second.size(); ++i)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }

    return 0;


}
