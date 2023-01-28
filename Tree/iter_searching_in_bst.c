#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

/*
//         5
//        /  \
//       3    6
//     /   \
//    1     4
*/

void inOrder(struct node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int IsBST(struct node *root)
{
    static struct node *pre = NULL;

    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0;
        }

        if (pre != NULL && root->data <= pre->data)
        {
            return 0;
        }
        pre = root;
        return IsBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {

        if (root->data == key)
        {
            return root;
        }

        else if (key > root->data)
        {
            root = root->right;
        }

        else
        {
            root = root->left;
        }
    }

    return NULL;
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    // printf("\n");
    inOrder(p);
    printf("\n");
    // if (IsBST(p))
    // {
    //     printf("yes,It is BTS\n");
    // }
    // else{
    //     printf("no,It's not BTS");
    // }
    printf("%d\n", IsBST(p));

    struct node *n = searchIter(p, 77);

    if (n != NULL)
    {
        printf("Found :%d\n", n->data);
    }
    else
    {
        printf("element isn't found");
    }
    return 0;
}
