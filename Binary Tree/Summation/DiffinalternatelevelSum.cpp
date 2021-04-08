#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int x)
    {
        data = x;
        left = right = NULL;
    }
};

void levelOrder(Node *root)
{
    std::queue<Node *> q;
    Node *curr;
    q.push(root);
    q.push(NULL);
    int level = 1;
    int osum = 0;
    int esum = 0;
    while(q.size() > 1)
    {

        curr = q.front();
        q.pop();
        if(curr == NULL)
        {
            level++;
            q.push(NULL);
            continue;
        }
        else
        {
            if(level%2 == 0)
                esum += curr->data;
            else
                osum += curr->data;

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }

    cout << "Maximum Level Sum : " << osum-esum;
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    levelOrder(root);

    return 0;
}
