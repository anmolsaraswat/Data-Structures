#include<cstring>
#include<iostream>
using namespace std;
#define MAX 100

struct Node {
    char data;
    Node *left, *right;
    Node(char x)
    {
        data = x;
        left = right = NULL;
    }
};

void storeInorder(Node *root, char arr[], int &i)
{
    if(root == NULL)
    {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] == root->data;
    storeInorder(root->right, arr, i);
}

void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

bool isSubtree(Node *T, Node *S)
{
    if(!S)
        return true;
    if(!T)
        return false;
    int m=0, n=0;
    char inT[MAX], inS[MAX];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';

    if(strstr(inT, inS) == NULL)
        return false;

    m =0 , n =0;
    char preT[MAX], preS[MAX];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';

    return (strstr(preT, preS) != NULL);
}

int main()
{
    Node *T = new Node('a');
    T->left = new Node('b');
    T->right = new Node('d');
    T->left->left = new Node('c');
    T->right->right = new Node('e');

    Node *S = new Node('a');
    S->left = new Node('b');
    S->left->left = new Node('c');
    S->right = new Node('d');

    if(isSubtree(T,S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
    return 0;
}
