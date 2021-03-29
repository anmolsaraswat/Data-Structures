#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
     Node *next;
};


void sortedInsert(Node **head_ref, int data)
{
    Node *current = *head_ref;
    Node *ptr = new Node();
    ptr->data =data;
    if(current == NULL)
    {
        ptr->next = ptr;
        *head_ref = ptr;
    }
    else if(current->data >= ptr->data)
    {
        while(current->next != *head_ref)
            current = current->next;
        current->next = ptr;
        ptr->next = *head_ref;
        *head_ref = ptr;
    }

    else
    {
        while(current->next != *head_ref && current->next->data < ptr->data)
            current = current->next;
        ptr->next = current->next;
        current->next = ptr;
    }

}

void print(Node *head)
{
    Node *tra = head;
    do
    {
        cout << tra->data << "  ";
        tra= tra->next;
    }
    while(tra!= head);
}
int main()
{
    int no, temp;
    cout << "No of elements in a Linked List:";
    cin >> no;
    Node *head = NULL;
    for(int i=0; i<no; i++)
    {
        cin >> temp;
        sortedInsert(&head, temp);
    }
    print(head);
}
