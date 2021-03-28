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


void splitList(Node **head_ref, Node **list1, Node **list2)
{
    Node *temp = *head_ref;
    Node *last = NULL;
    Node *slw = *head_ref;
    Node *middle = NULL;
    while(temp->next!= *head_ref)
    {
        temp = temp->next;
    }
    last = temp;
    temp = *head_ref;
    while(temp->next != *head_ref && temp->next->next != *head_ref)
    {
        temp = temp->next->next;
        slw = slw->next;
    }
    middle = slw;
    *list2 = middle->next;
    *list1 = *head_ref;
    middle->next = *head_ref;
    last->next = *list2;
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
    cout<<endl;
}
int main()
{
    Node *head = NULL;
    Node *list1 = NULL;
    Node *list2 = NULL;
    push(&head, 12);
    push(&head, 44);
    push(&head, 2);
    push(&head, 8);
    push(&head, 90);

    splitList(&head, &list1, &list2);
    //printList(head);
    printList(list1);
    printList(list2);
}
