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

bool identicalTrees(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(root2 == NULL)
        return false;

    queue <Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {
        Node *n1 = q1.front();
        Node *n2 = q2.front();

        if(n1->data != n2->data)
            return false;
        q1.pop();
        q2.pop();

        if(n1->left && n2->left)
        {
            q1.push(n1->left);
            q2.push(n2->left);
        }
        else if(n1->left || n2->left)
            return false;

        if(n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if(n1->right || n2->right)
            return false;
    }
    return true;


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


    if(identicalTrees(root1, root2))
        cout << "Both tree are identical";
    else
        cout << "Trees are not identical.";

    return 0;

}
