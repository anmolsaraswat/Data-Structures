#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *next,*right;
    Node(int x)
    {
        data = x;
        left = next = right = NULL;
    }
};

void populateInorderSuccessor(Node *root)
{
    static Node *c = NULL;
    if(root)
    {
        populateInorderSuccessor(root->right);
        root->next = c;
        c = root;
        populateInorderSuccessor(root->left);
    }

}

void printInS(Node *root)
{
    if(root)
    {
        printInS(root->left);
        int p = root->next != NULL ? root->next->data : -1;
        cout << p << " ";
        printInS(root->right);
    }

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
    populateInorderSuccessor(root);

    printInS(root);
    return 0;
}
