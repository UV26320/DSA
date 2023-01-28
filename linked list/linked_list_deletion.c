#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklisttravasal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// case 1
struct node *deletefirst(struct node *head)
{
    struct node *ptr = head;

    head = head->next;
    free(ptr);

    return head;
}

// case 2

struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case 3

struct node *deleteatlast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// case 4

struct node *deleteatvalue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *four;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 55;
    third->next = four;

    four->data = 78;
    four->next = NULL;

    printf("linked list before a deletion \n");
    linklisttravasal(head);
    printf("linked list after a deletion \n");
    head = deletefirst(head);
    // head = deleteatindex(head, 2);
    // head = deleteatlast(head);
    // head = deleteatvalue(head, 55);
    linklisttravasal(head);
    return 0;
}