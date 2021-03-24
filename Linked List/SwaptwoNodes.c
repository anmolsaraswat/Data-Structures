#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printLinkedList(struct Node *head)
{
    struct Node *traverse;
    traverse = head;
    while(traverse != NULL)
    {
        if(traverse->next == NULL)
        {
            printf("%d", traverse->data);
        }
        else
        {
            printf("%d -->", traverse->data);
        }
        traverse = traverse->next;
    }
}

void swapnodes(struct Node **head, int x, int y)
{
    if(x == y)
        return;

    struct Node *prevX =NULL, *currX = *head;
    while(currX && currX->data!=x)
    {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *prevY=NULL, *currY = *head;
    while(currY && currY->data!=y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL)
        return;

    if(prevX !=NULL)
    {
        prevX->next = currY;
    }
    else
    {
        *head = currY;
    }

    if(prevY != NULL)
    {
        prevY->next = currX;
    }
    else
    {
        *head = currX;
    }


    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX ->next = temp;
}

int main()
{
    struct Node *head = NULL;
    struct Node *str = NULL;
    struct Node *ptr = NULL;
    int no_of_ele, node1val, node2val;

    printf("No. of elements in Linked List:");
    scanf("%d", &no_of_ele);

    head = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &(head->data));
    head->next = NULL;
    for(int i=0; i<(no_of_ele-1); i++)
    {
        if(i==0)
        {
            ptr = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &(ptr->data));
            head->next = ptr;
            ptr->next = NULL;
        }
        else
        {
            str = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &(str->data));
            str->next = NULL;
            ptr->next = str;
            ptr = str;
        }
    }
    printf("Enter the 2 nodes that needs to be swaped");
    scanf("%d", &node1val);
    scanf("%d", &node2val);
    swapnodes(&head, node1val, node2val);
    printLinkedList(head);
    return 0;
}
