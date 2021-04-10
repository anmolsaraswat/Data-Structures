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

string areMirrors(Node *root1, Node *root2)
{
    stack<Node *> st1, st2;
    while(1)
    {
        while(root1 && root2)
        {
            if(root1->data != root2->data)
                return "No.";

            st1.push(root1);
            st2.push(root2);
            root1 = root1->left;
            root2 = root2->right;
        }

        if(!(root1 == NULL && root2 == NULL))
            return "No.";

        if(!st1.empty() && !st2.empty())
        {
            root1 = st1.top();
            root2 = st2.top();

            st1.pop();
            st2.pop();

            root1 = root1->right;
            root2 = root2->left;
        }
        else
            break;
    }
    return "Yes.";
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(4);
    root2->right->left = new Node(5);

    cout << areMirrors(root1, root2);
    return 0;
}
