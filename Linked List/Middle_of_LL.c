#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void getMiddleElement(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle Element of Linked List: %d", slow->data);
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
    getMiddleElement(head);
        return 0;
}
