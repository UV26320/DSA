#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arry;
};

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

int parenthesis(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arry = (char *)malloc(sp->size * sizeof(char));

for (int i = 0; i < exp[i] != '\0'; i++)
{
    if (exp[i] == '(')
    {
        push(sp, '(');
    }

    else if (exp[i] == ')')
    {
        if (imapty(sp))
        {
            return 0;
        }
        pop(sp);
    }
}

    if (imapty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    char *exp = "8*(9))";

        if (parenthesis(exp))
    {
        printf("parenthesis is matching");
    }
    else
    {
        printf("parenthesis is not matching");
    }

    return 0;
}