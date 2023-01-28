#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arry;
};

int isimapty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Stack is overflow ! u cann't push %d to the stack \n",val);
    }
    else
    {
        ptr->top++;
        ptr->arry[ptr->top] = val;
    }
}


int pop(struct stack *ptr)
{
    if (isimapty(ptr))
    {
        printf("Stack is underflow u cann't pop from the stack");
        return -1;
    }
    else
    {
        int val=ptr->arry[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack*sp,int i)
{
    int position = sp->top-i+1;
    if (position<0)
    {
        printf("Not a valid postion in this stack");
    }
    else
    {
        return sp->arry[position];
    }
    
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 80;
    sp->top = -1;
    sp->arry = (int *)malloc(sp->size * sizeof(int));

    printf("stack has been creacted succesfull\n");

    printf("Befor pusing full: %d\n", isfull(sp));
    printf("Befor pusing emapty: %d\n", isimapty(sp));

    push(sp, 40);
    push(sp, 40);
    push(sp, 4);
    push(sp, 70);
    push(sp, 60);
    push(sp, 80);
    push(sp, 41);
    push(sp, 54);
    push(sp, 86);
    push(sp, 40);   
    push(sp, 77);    
    push(sp, 75);   
    
    printf("After pusing full: %d\n", isfull(sp));
    printf("After pusing emapty: %d\n", isimapty(sp));
    
    for (int i = 1; i <=sp->top+1; i++)
    {
        printf("The value at postion %d is %d\n",i,peek(sp,i)); // revers print thase bcs stack is LIFO type linear data
    }
    

    return 0;
}