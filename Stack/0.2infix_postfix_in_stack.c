#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arry;
};

int top(struct stack *sp)
{

    return sp->arry[sp->top];
}

int imapty(struct stack *s1)
{
    if (s1->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(struct stack *s1)
{
    if (s1->top == s1->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (full(ptr))
    {
        printf("Stack is overflow ! u cann't push %d to the stack \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arry[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (imapty(ptr))
    {
        printf("Stack is underflow u cann't pop from the stack");
        return -1;
    }
    else
    {
        char val = ptr->arry[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char a)
{
    if (a == '*' || a == '/')
    {
        return 3;
    }

    else if (a == '+' || a == '-')
    {
        return 2;
    }

    else
    {
        return 0;
    }
}

int isopreater(char a)
{
    if (a == '*' || a == '/' || a == '+' || a == '-')
        return 1;
    else
        return 0;
}

char *infixtopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arry = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix travsal
    int j = 0; // Track postfix addtion

    while (infix[i] != '\0')
    {
        if (!isopreater(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }

        else
        {
            if (precedence(infix[i]) > precedence(top(sp)))
            {
                push(sp, infix[i]);
                i++;
            }

            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!imapty(sp))
    {
        postfix[i] = pop(sp);
        j++;
    }
    postfix = '\0';

    return postfix;
}

int main()
{
    char *infix = "a-b";
    printf("postfix is %s", infixtopostfix(infix));
    return 0;
}