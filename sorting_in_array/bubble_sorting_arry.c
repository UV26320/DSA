#include <stdio.h>

void printarry(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// void bubblesort(int a[], int n)
// {
//     int temp;

//     for (int i = 0; i < n - 1; i++) //  For number of passes
//     {
//         printf("Number of the passes is %d\n", i + 1);
//         for (int j = 0; j < n - 1 - i; j++) //  For comparison of each passes
//         {
//             if (a[j] > a[j + 1])
//             {
//                 temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             }
//         }
//     }
// }

void bubblesortAdaptive(int a[], int n)
{
    int temp;
    int issorted = 0;

    for (int i = 0; i < n - 1; i++) //  For number of passes
    {
        printf("Number of the passes is %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++) //  For comparison of each passes
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                issorted = 0;
            }
        }
        if (issorted)
            return;
    }
}

int main()
{

    // bubblesort for Adaptive algorithum(arry is alrady sorted...)
     //int a[] = {1, 2, 3, 4, 56, 66, 77};
    int a[]={111,22,3,454,756,666,777};
    int n = 6;
    printarry(a, n);


    //bubblesort(a, n); // funcation to sort the arry
   bubblesortAdaptive(a, n); // funcation to sort the arry
    printarry(a, n);
    return 0;
}