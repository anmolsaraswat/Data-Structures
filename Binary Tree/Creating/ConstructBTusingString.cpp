#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int findIndex(string str, int si, int ei)
{
    if(si>ei)
        return -1;
    stack<char> s;

    for(int i= si; i<=ei; i++)
    {
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            if(s.top() == '('){
                s.pop();

                if(s.empty())
                    return i;
               }
        }
    }
    return -1;
}


Node* constructTree(string str, int si, int ei)
{
    if(si>ei)
        return NULL;

    Node* root = newNode(str[si] - '0');
    int index = -1;
    if(si+1 <=ei && str[si+1] == '(')
        index = findIndex(str, si+1, ei);

    if(index != -1){
        root->left = constructTree(str, si+2, index-1);
        root->right = constructTree(str, index+2, ei-1);
    }
    return root;
}

int main()
{
    string str= "4(2(3)(1))(6(5))";
    int start = 0;
    Node *root = constructTree(str, 0, str.size()-1);
    preorder(root);
    return 0;
}
