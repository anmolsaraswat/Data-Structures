#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head)
{
   struct Node *traverse;
    traverse = head;
    while (traverse != NULL)
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

int main(){

    struct Node *head = NULL;
    struct Node *str = NULL;
    struct Node *ptr = NULL;
    int no_of_ele;

    printf("No of elements in a linked list: ");
    scanf("%d", &no_of_ele);
    head  = (struct Node*)malloc(sizeof(struct Node));
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
    printLinkedList(head);
        return 0;
}
