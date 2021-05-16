#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val){
        this->data = val;
        left = right = NULL;
    }
};

void printkdistanceNodeDown(struct Node* root, int k)
{
    if(root == NULL || k <0) return;
    if(k==0)
    {
        cout << root->data << endl;
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(struct Node* root, struct Node* target, int k)
{
    if(root == NULL) return -1;

    if(root == target){
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);
    if(dl!=-1)
    {
        if(dl+1 == k)
            cout << root->data << endl;
        else
            printkdistanceNodeDown(root->right, k-dl-2);
        return 1+dl;
    }

    int dr = printkdistanceNode(root->right, target, k);
    if(dr !=-1)
    {
        if(dr + 1 == k)
            cout << root->data << endl;
        else
            printkdistanceNodeDown(root->left, k-dr-2);
        return 1+dr;
    }
    return -1;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;

}
