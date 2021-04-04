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
void printPathsUtil(struct Node *curr_node, int sum, int curr_sum, vector<int> &path);
void printPaths(struct Node *root, int sum)
{
    vector<int> path;
    printPathsUtil(root, sum, 0, path);
}

void printPathsUtil(struct Node *curr_node, int sum, int curr_sum, vector<int> &path)
{
    if(!curr_node)
        return;

    curr_sum += curr_node->data;
    path.push_back(curr_node->data);

    if(curr_sum == sum)
    {
        cout << "Path found : ";
        for(int i=0; i<path.size();i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    if(curr_node->left != NULL)
    {
        printPathsUtil(curr_node->left, sum, curr_sum, path);
    }

    if(curr_node->right!=NULL)
    {
        printPathsUtil(curr_node->right, sum, curr_sum, path);
    }
    path.pop_back();
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(28);
    root->right = new Node(13);

    root->right->left = new Node(14);
    root->right->right = new Node(15);
    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);

    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);

    int sum = 38;

    printPaths(root, sum);

    return 0;
}
