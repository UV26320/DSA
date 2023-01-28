#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *right;
    struct node *left;
    int hight;
};

int max(int a, int b)
{

    return a > b ? a : b;
}

int GETHIGHT(struct node *n)
{

    if (n == NULL)
        return 0;
    return n->hight;
}

struct node *createnode(int key)
{

    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->key = key;
    Node->right = NULL;
    Node->right = NULL;
    Node->hight = 1;
    return Node;
}

int GetBalanceFactor(struct node *n)
{
    if (n == NULL){
        return 0;
    }
    return (GETHIGHT(n->left) - GETHIGHT(n->right));
}

struct node *RIGHTROTATA(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->hight = max(GETHIGHT(x->right), GETHIGHT(x->left)) + 1;
    y->hight = max(GETHIGHT(y->right), GETHIGHT(y->left)) + 1;

    return x;
}

struct node *LEFTROTATA(struct node *x)
{

    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->hight = max(GETHIGHT(x->right), GETHIGHT(x->left)) + 1;
    y->hight = max(GETHIGHT(y->right), GETHIGHT(y->left)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{

    if (node == NULL)
        return (createnode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->hight = 1 + max(GETHIGHT(node->right), GETHIGHT(node->left));
    int BF = GetBalanceFactor(node);

    // left left case
    if (BF > 1 && key < node->left->key)
    {
        return RIGHTROTATA(node);
    }

    // right right case
    if (BF < -1 && key > node->right->key)
    {
        return LEFTROTATA(node);
    }

    // left right  case
    if (BF > 1 && key > node->left->key)
    {
        node->left = LEFTROTATA(node->left);
        return RIGHTROTATA(node);
    }
    // right left case
    if (BF < -1 && key < node->right->key)
    {
        node->right = RIGHTROTATA(node->right);
        return LEFTROTATA(node);
    }

    return node;
}

void preOrder(struct node *root)
{

    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);

    preOrder(root);
    return 0;
}
