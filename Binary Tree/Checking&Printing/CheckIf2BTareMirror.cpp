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

int mirrorTree(Node* a, Node *b)
{
    if(a == NULL && b == NULL)
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    return (
            a->data == b->data &&
            mirrorTree(a->left, b->right) &&
            mirrorTree(a->right, b->left)
            );
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);


    if(mirrorTree(root1, root2))
        cout << "Both tree are mirror of each other";
    else
        cout << "Trees are not mirror of each other.";

    return 0;

}
