#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int data)
    {
        this->data =data;
        left = right = NULL;
    }
};
void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for(i=1; i<=h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level >1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int height(node *node)
{
    if(node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if(lheight > rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Level Order Traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}
