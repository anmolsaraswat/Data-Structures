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

bool isLeaf(Node *root)
{
    if(!root)
        return false;
    if(!root->left && !root->right)
        return true;
    return false;
}

bool isSame(Node *root1, Node *root2)
{
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root1);
    s2.push(root2);

    while (!s1.empty() || !s2.empty())
    {
        if(s1.empty() || s2.empty())
            return false;

        Node *temp1 = s1.top();
        s1.pop();
        while(temp1 != NULL && !isLeaf(temp1))
        {
            if(temp1->right)
                s1.push(temp1->right);
            if(temp1->left)
                s1.push(temp1->left);
            temp1 = s1.top();
            s1.pop();
        }
        Node *temp2 = s2.top();
        s2.pop();
        while(temp2 != NULL && !isLeaf(temp2))
        {
            if(temp2->right)
                s2.push(temp2->right);
            if(temp2->left)
                s2.push(temp2->left);
            temp2 = s2.top();
            s2.pop();
        }

        if(!temp1 && temp2)
            return false;
        if(temp1 && !temp2)
            return false;
        if(temp1 && temp2)
            return temp1->data == temp2->data;
    }
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node* root2 = new Node(0);
    root2->left = new Node(1);
    root2->right = new Node(5);
    root2->left->right = new Node(4);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    if(isSame(root1, root2))
        cout << "Same";
    else
        cout << "Not Same";

    return 0;
}
