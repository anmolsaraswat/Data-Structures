#include<bits/stdc++.h>
using namespace std;

int path[1000];
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void print(int len)
{
    for(int i=0; i<len; i++)
        cout << path[i] << " ";
    cout << endl;
}
void printPath(Node *root, int index)
{
    path[index++] = root->data;
    if(root->left == NULL && root->right == NULL)
    {
        print(index);
        return;
    }
    printPath(root->left, index);
    printPath(root->right, index);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printPath(root, 0);

    return 0;
}
