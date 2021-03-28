#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};


void push(Node **head_ref, int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    Node *temp = *head_ref;

    if(*head_ref != NULL)
    {
        while(temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr;
        ptr->next =*head_ref;
    }
    else
    {
        ptr->next = ptr;
        *head_ref = ptr;
    }
}

void printList(Node *head)
{
    Node *traverse = head;
    do
    {
        cout<< traverse->data << " ";
        traverse = traverse->next;
    }
    while(traverse!= head);
}
int main()
{
    Node *head = NULL;
    push(&head, 12);
    push(&head, 44);
    push(&head, 2);
    push(&head, 8);
    push(&head, 90);

    printList(head);
}
