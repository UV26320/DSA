#include <stdio.h>

int linearsearch(int arry[], int size, int element)
{
    for (int i = 0; i < size; i++)        /* ahi return -1 aetle bar rakhu che ke karn ke
                                           for loop akha arry ma chalse and if (arry[i]==element)
                                           thase aetle te arry print thai jai but akha arry ma 
                                           aa element na hou to ??? to ane to j return -1 print kare
                                           soo
                                           return -1 bar rakhu
                                                   */ 
    {
        if (arry[i] == element)
        {
            return i;
        }
    }
    return -1;   
}

int main()
{
    int arry[] = {1, 12, 13, 4, 5, 78, 8, 89, 52, 45, 6, 7};
    int size = sizeof(arry) / sizeof(int);
    int element;
    printf("element is : \n");
    scanf("%d", &element);
    int searchindex = linearsearch(arry, size, element);
    printf("The element %d is found at %d index \n", element, searchindex);
    return 0;
}