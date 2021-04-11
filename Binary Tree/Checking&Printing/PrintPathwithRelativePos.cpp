#include<bits/stdc++.h>
using namespace std;

#define MAX_PATH_SIZE 1000

struct Node {
    char data;
    Node *left, *right;
    Node(char x)
    {
        data = x;
        left = right = NULL;
    }
};

struct PATH {
    int Hd;
    char data;
};

void printPath(vector<PATH> path, int size)
{
    int minimum_Hd = INT_MAX;
    PATH p;
    for(int it=0; it<size; it++)
    {
        p = path[it];
        minimum_Hd = min(minimum_Hd, p.Hd);
    }
    for(int it=0; it<size; it++)
    {
        p = path[it];
        int noOfUnderScores = abs(p.Hd-minimum_Hd);
        for(int i = 0; i<noOfUnderScores; i++)
            cout << "_";
        cout << p.data << endl;
    }
    cout << "============================== " << endl;
}

void printAllPathsUtil(Node *root, vector<PATH> &AllPath, int HD, int order)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        AllPath[order] = (PATH{HD, root->data});
        printPath(AllPath, order+1);
        return;
    }

    AllPath[order] = (PATH{HD, root->data});

    printAllPathsUtil(root->left, AllPath, HD-1, order+1);
    printAllPathsUtil(root->right, AllPath, HD+1, order+1);
}

void printAllPaths(Node *root)
{
    if(!root)
        return;
    vector<PATH> Allpaths(MAX_PATH_SIZE);
    printAllPathsUtil(root, Allpaths, 0, 0);
}

int main()
{
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');
    printAllPaths(root);
    return 0;
}
