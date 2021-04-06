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
    int max_sum = 0;
    int sum = 0;
    while(q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if(curr == NULL)
        {
            q.push(NULL);
            if(sum > max_sum)
            {
                max_sum = sum;
            }
            sum = 0;
            continue;
        }
        else
        {
            sum += curr->data;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    if(sum > max_sum)
        max_sum = sum;
    cout << "Maximum Level Sum : " << max_sum;
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

    levelOrder(root);

    return 0;
}
