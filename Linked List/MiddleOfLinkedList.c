#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void middleLL(struct Node *head)
{
    struct Node *t1, *t2;
    t1 = head;
    t2 = head;
    while(t1->next != NULL && t1->next->next != NULL)
    {
        t2 = t2->next;
        t1 = t1->next->next;
    }
    printf("The middle element of the Linked list is %d", t2->data);
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

    middleLL(head);
    return 0;
}
