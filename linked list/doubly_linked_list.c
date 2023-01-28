
#include <stdio.h>
#include <stdlib.h>

// defining node structure.
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

// creating fuction which can travel forward -> print and backward -> print the elements.

struct node *forward(struct node *head)
{

    do
    {
        printf("The element value is: %d\n", head->data);
        printf("The element previous node address is: %x\n", head->previous);
        printf("The element next node address is: %x\n", head->next);
        head = head->next;
        if (head->next == NULL)
        {
            printf("The element value is: %d\n", head->data);
            printf("The element previous node address is: %x\n", head->previous);
            printf("The element next node address is: %x\n", head->next);
        }

    } while (head->next != NULL);
}

struct node *backward(struct node *fourth)
{

    do
    {
        printf("The element value is: %d\n", fourth->data);
        printf("The element previous node address is: %x\n", fourth->previous);
        printf("The element next node address is: %x\n", fourth->next);
        fourth = fourth->previous;
        if (fourth->previous==NULL)
        {
        printf("The element value is: %d\n", fourth->data);
        printf("The element previous node address is: %x\n", fourth->previous);
        printf("The element next node address is: %x\n", fourth->next);
        }
        
    } while (fourth->previous != NULL);
}

int main()
{
    // creating nodes.
    struct node *head, *second, *third, *fourth;

    // allocating the memory in heap for nodes.

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // defining values for all nodes.

    // head note values

    head->data = 23;
    head->previous = NULL;
    head->next = second;

    // second note values
    second->data = 34;
    second->previous = head;
    second->next = third;

    // third note values
    third->data = 56;
    third->previous = second;
    third->next = fourth;

    // Fourth note values
    fourth->data = 52;
    fourth->previous = third;
    fourth->next = NULL;

    // calling forward and backward functions.

    forward(head);
    printf("*****************************************\n\n");
    printf("*****************************************\n\n");
    backward(fourth);

    return 0;
}