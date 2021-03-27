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

mergeSorted(struct Node **a, struct Node **b)
{
    struct Node *h3 = NULL;
    struct Node *tra;
    struct Node *tra1 = *a;
    struct Node *tra2 = *b;
    h3 = (struct Node*)malloc(sizeof(struct Node));
    h3->data = 0;
    tra=h3;
    while(1)
    {
        if(tra1 == NULL)
        {
            tra->next = tra2;
            break;
        }
        if(tra2 == NULL)
        {
            tra->next = tra1;
            break;
        }
        if((tra1->data) < (tra2->data))
        {
            tra->next = tra1;
            tra1=tra1->next;
            tra = tra->next;
            tra->next = NULL;
        }
        else if((tra1->data) > (tra2->data))
        {
            tra->next = tra2;
            tra2 = tra2->next;
            tra = tra->next;
            tra->next = NULL;
        }
    }
    printLinkedList(h3->next);

}

int main()
{
    struct Node *h1 = NULL;
    struct Node *str = NULL;
    struct Node *ptr = NULL;
    int no_of_ele1, no_of_ele2;

    printf("No. of elements in Linked List 1 :");
    scanf("%d", &no_of_ele1);

    h1 = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &(h1->data));
    h1->next = NULL;
    for(int i=0; i<(no_of_ele1-1); i++)
    {
        if(i==0)
        {
            ptr = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &(ptr->data));
            h1->next = ptr;
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
    struct Node *h2 = NULL;

    printf("No. of elements in Linked List 2 :");
    scanf("%d", &no_of_ele2);

    h2 = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &(h2->data));
    h2->next = NULL;
    for(int i=0; i<(no_of_ele2-1); i++)
    {
        if(i==0)
        {
            ptr = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d", &(ptr->data));
            h2->next = ptr;
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
    mergeSorted( &h1, &h2);
    return 0;
}
