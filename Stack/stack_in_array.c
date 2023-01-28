#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arry;
};

// int imapty(struct stack *s1)
// {
//     if (s1->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int imapty(struct stack s1)
{
    if (s1.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// int full(struct stack *s1)
// {
//     if (s1->top == s1->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int full(struct stack s1)
{
    if (s1.top == s1.size - 1)
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
    struct stack s;

    s.size = 80;
    s.top = -1;
    s.arry = (int *)malloc(s.size * sizeof(int));
    // s.arry[0] = 4;
    // s.top++;

    // struct stack *s;

    // s->size = 80;
    // s->top = -1;
    // s->arry = (int *)malloc(s->size * sizeof(int));
    // s->arry[0] = 4;
    // s->top++;

    // cheack stack is emapyt
    if (imapty(s))
    {
        printf("stack is emapty");
    }
    else
    {
        printf("stack is not emapty");
    }

    return 0;
}