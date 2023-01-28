# include <stdio.h>
# include <malloc.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createnode(int data)
{
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->right=NULL;
    return n;
}
int main(){

    // struct node* p;
    // p=(struct node*)malloc(sizeof(struct node));
    // p->data=4;
    // p->right=NULL;
    // p->right=NULL;
    
    // struct node* p1;
    // p1=(struct node*)malloc(sizeof(struct node));
    // p1->data=7;
    // p1->right=NULL;
    // p1->right=NULL;

    // struct node* p2;
    // p2=(struct node*)malloc(sizeof(struct node));
    // p2->data=4;
    // p2->right=NULL;
    // p2->right=NULL;
     
     struct node*p = createnode(4);
     struct node*p1= createnode(7);
     struct node*p2= createnode(4);
     
     p->left=p1;
     p->right=p2;

    return 0;
}