#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;\
    bool t;
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

detectLoop(head)
{
    struct Node *traverse, *temp;
    bool check = false;
    int count = 0;
    traverse = head;
    while(traverse != NULL)
    {
        if(traverse->t)
        {
            printf("The linked List contains a loop \n");
            check = true;
            temp = traverse;
            break;
        }
        traverse->t = true;
        traverse=traverse->next;
    }
    if(check)
    {
        traverse = temp->next;
        count =1;
        while(traverse != temp)
        {
            traverse = traverse->next;
            count++;
        }
        printf("The length of the loop is %d", count);
    }

}

int main()
{
    struct Node *head = NULL;
    struct Node *str = NULL;
    struct Node *ptr = NULL;
    int no_of_ele;

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
    head->next->next->next = head;
    detectLoop(head);

    return 0;
}
