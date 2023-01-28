#include <stdio.h>

void printarry(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selecatininsort(int a[], int n)
{

    printf("Selecation of sortig is... \n");
    int indexofmin,temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i; /* suppose first element is minimum in this
                        soo now we compare this element in others
                        elemnts  */
          for (int j = i+1; j < n; j++)       
          {
                if (a[j]<a[indexofmin])
                {
                    indexofmin=j;
                }  
                temp=a[i];             // this methode is know as swap methode 
                a[i]=a[indexofmin];
                a[indexofmin]=temp;             
          }                  
    }
}

int main()
{      
    /*    i->
          0...........(n-1)
           |           |
    index  0 1 2 3  4  5
          20 8 4 3 10 15   */

    /*    i->
          0...........(n-1)  
            j->
          (i+1)......(n)
             |         |
          0  1 2 3  4  5
          20 8 4 3 10 15
          |  - - - - - - - - - - 
          |                   |
          |                   |
          |                   |               
          indexofmin   >    j
          
          then
          exchang
          indexofmin and j  
          but which way !!!
          this way is swap method 
          
          */


    int a[] = {20, 8, 4, 3, 10, 15};
    int n = 6;
    printarry(a, n);
    selecatininsort(a, n);
    printarry(a, n);

    return 0;
}