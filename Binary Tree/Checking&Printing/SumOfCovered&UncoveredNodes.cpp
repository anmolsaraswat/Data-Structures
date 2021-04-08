#include<bits/stdc++.h>
using namespace std;

int totalSum = 0;
int uncovered =0;
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void tsum(Node *root)
{
    if(!root)
        return;
    totalSum += root->data;
    tsum(root->left);
    tsum(root->right);
}

void unsum(Node *root)
{
    int lsum =0, rsum=0;
    struct Node *lt = root;
    while(1)
    {
        if(!lt)
            break;
        lsum += lt->data;
        if(lt->left)
            lt = lt->left;
        else
            lt = lt->right;
    }
    cout << "Left Sum " << lsum;
    struct Node *rt = root;
    while(1)
    {
        if(!rt)
            break;
        rsum += rt->data;
        if(rt->right)
            rt=rt->right;
        else
            rt = rt->left;
    }
    uncovered = lsum + rsum - (root->data);
}

int main()
{
    struct Node *root = new Node(9);
    root->left = new Node(4);
    root->right = new Node(17);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);

    tsum(root);
    unsum(root);
    cout <<  "Total sum of Nodes : " << totalSum << endl;
    cout << "Total of Uncovered Nodes : " << (totalSum-uncovered);
    return 0;
}
