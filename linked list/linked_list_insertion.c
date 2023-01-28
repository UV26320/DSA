#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case 2
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;

    while (i != index - 1) 
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

// case 4

struct Node *insertafternode(struct Node *head,struct Node *privnode,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
   
    ptr->next=privnode->next;
    privnode->next=ptr;
    return head;
}

//case 5

struct Node *insert_in_ascending(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    if (head->data >= data)
    {
        temp->data = data;
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        while (p->next != NULL && p->next->data <= data)
        {
            p = p->next;
        }
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
        return head;
    }
}




int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
     //head = insertAtFirst(head, 56);
     head = insertAtIndex(head, 56, 2);
    //head = insertAtEnd(head, 56);
    //head = insertafternode(head,second,56);
    //head=insert_in_ascending(head,40);
    //head=insert_in_ascending(head,14);
    printf("Linked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}