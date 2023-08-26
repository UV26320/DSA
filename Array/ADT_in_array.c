# include <stdio.h>
# include <stdlib.h>

struct myarray 
{   
    int total_size;
    int used_size;
    int *ptr;
};

void creatarry(struct myarray *a,int tsize,int usize)
{
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr=(int*)malloc(tsize*sizeof(int));/
      a->total_size=tsize;
      a->used_size=usize;
      a->ptr=(int*)malloc(tsize*sizeof(int));
}

void show(struct myarray *a)
{
   for (int i = 1; i <= (a->used_size); i++)
   {
     printf("%d\n",(a->ptr)[i]);
   } 
}

void setvalue(struct myarray *a)
{
   for (int i = 1; i <=a->used_size; i++)
   {
     printf("Enter element %d\n",i);
     scanf("%d",&((a->ptr)[i]));
   }
   
}


int main(){

    struct myarray *marks;
    creatarry(marks,10,2);
    printf("we have set a value\n");
    setvalue(marks);
    printf("now we can see marks\n");
    show(marks);    
    return 0;
}
