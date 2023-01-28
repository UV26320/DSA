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
// this code is insertion
int addindex(int arry[], int size, int capacity, int element, int index)
{

    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arry[i + 1] = arry[i];
    }
    arry[index] = element;
    return 1;
}

int main()
{
    int arry[100] = {1, 2, 42, 45, 47, 54, 65};
    int size = 7, capacity, element = 66, index = 3;
    display(arry, size);
    addindex(arry, size, 100, element, index);
    size += 1;
    display(arry, size);
    return 0;
}