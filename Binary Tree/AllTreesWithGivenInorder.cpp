#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
};


void preorder(Node *root)
{
    if(root)
    {
        cout << root->key;
        preorder(root->left);
        preorder(root->right);
    }
}

vector<Node *> getTrees(int arr[], int s, int e)
{
    vector<Node *> trees;
    if(s > e)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=s; i<=e; i++)
    {
        vector<Node *> ltrees = getTrees(arr, s, i-1);
        vector<Node *> rtrees = getTrees(arr, i+1, e);
        for(int j=0; j<ltrees.size(); j++)
        {
            for(int k =0; k<rtrees.size(); k++)
            {
                Node *node = newNode(arr[i]);
                node->left = ltrees[j];
                node->right = rtrees[k];
                trees.push_back(node);
            }
        }
    }
    return trees;
}

int main()
{
    int in[] = {4, 5, 7};
    int n = sizeof(in)/sizeof(in[0]);
    vector<Node *> trees = getTrees(in, 0, n-1);
    cout << "Preorder Traversals of different Binary trees : " << endl;
    for(int i=0; i<trees.size(); i++)
    {
        preorder(trees[i]);
        cout << endl;
    }
    return 0;
}
