#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

void verticalSumUtil(struct Node *root, std::map<int, int> &m, int index)
{
    if(root == NULL)
        return;
    m[index] += root->data;
    verticalSumUtil(root->left, m, index -1);
    verticalSumUtil(root->right, m, index +1);
}



void verticalSum(struct Node *root)
{
    std::map<int,int> Vsum;
    map<int,int>::iterator itr;
    verticalSumUtil(root, Vsum, 0);

    for(itr = Vsum.begin(); itr!=Vsum.end(); ++itr)
    {
        cout << itr->second << " ";
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

    verticalSum(root);
    return 0;
}
