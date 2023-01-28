#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node * inorderpredecessor(struct node*root){
    
    root=root->left;
    while(root->right!=NULL)
    {
       root=root->right; 
    }
   return root;
}

struct node *deletation(struct node *root, int value)
{
    struct node *ipre;
    if (root==NULL)
    {
        return NULL;
    }

    if (root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
     
    // Searching for the node to the delete
    if (value < root->data)
    {
        root->left=deletation(root->left, value);
    }

    else if (value > root->data)
    {
        root->right=deletation(root->right, value);
    }

    // deletion strategy when we found a delete node
    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left=deletation(root->left, ipre->data);
    }

    return root;
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*
//         5
//        /  \
//       3    6
//     /   \
//    1     4
*/

    inOrder(p);
    deletation(p, 4);
    printf("\n");
    inOrder(p);

    return 0;
}
