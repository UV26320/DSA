#include <stdio.h>

void printarry(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{

    int pivot = a[low];
    int i, temp;
    int j;
    i = low + 1;
    j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;         // return j aetle karu ke pivot element ae 
}                     // swap thai ne j ma 

int quicksort(int a[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);

        quicksort(a, low, partitionindex - 1);
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{

    int a[] = {20, 8,8, 4, 3, 10, 15, 45, 85, 95, 100};
    int n = 10;
    printarry(a, n);
    quicksort(a, 0, n - 1);
    printarry(a, n);

    return 0;
}