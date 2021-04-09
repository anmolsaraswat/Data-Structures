#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int search(char arr[], int strt, int end, char value)
{
    int i;
    for(i = strt; i<=end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

Node *buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
    if(inStrt > inEnd)
        return NULL;
    Node *tNode = new Node(pre[preIndex++]);

    if(inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex-1);
    tNode->right = buildTree(in, pre, inIndex+1, inEnd);

    return tNode;
}
void printInorder(Node *root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

}

int main()
{
    char in[] = { 'D',  'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D' , 'E', 'C', 'F' };
    int len = sizeof(in)/sizeof(in[0]);
    Node *root = buildTree(in, pre, 0, len-1);

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
