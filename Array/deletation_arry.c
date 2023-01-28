#include <stdio.h>

// this code is traversal
void display(int arry[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arry[i]);
    }
    printf("\n");
}
// this code is deletation
int deletation(int arry[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arry[i] = arry[i + 1];
    }
}

int main()
{           //index  0  1   2   3   4   5   6
    int arry[100] = {1, 2, 42, 45, 47, 54, 65};
    int size = 7, index = 4;
    display(arry, size);
    deletation(arry, size, index);
    size -= 1;
    display(arry, size);
    return 0;
}