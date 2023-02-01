#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printarry(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void countsort(int a[], int n)
{
    int i, j;

    int max = maximum(a, n); // find the maximum number

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    i = 0;   // counter for count arry 
    j = 0;   // counter for given arry  

    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a[] = {1, 45, 4, 5, 8, 9, 10, 1, 23, 78};
    int n = 10;
    printarry(a, n);
    countsort(a, n);
    printarry(a, n);

    return 0;
}