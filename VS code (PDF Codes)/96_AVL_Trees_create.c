#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
    int height;
} *root = NULL;

int node_height(struct node *p)
{
    int rh;
    int lh;
    rh = p && p->rchild ? p->rchild->height : 0;
    lh = p && p->lchild ? p->lchild->height : 0;

    return rh > lh ? rh + 1 : lh + 1;
}
int balance_factor(struct node *p)
{
    int rh;
    int lh;
    rh = p && p->rchild ? p->rchild->height : 0;
    lh = p && p->lchild ? p->lchild->height : 0;

    return lh - rh;
}

struct node *ll_rotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = node_height(p);
    pl->height = node_height(pl);
    if (root = p)
        root = pl;

    return pl;
}

struct node *lr_rotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = node_height(pl);
    p->height = node_height(p);
    plr->height = node_height(plr);
    if (root == p)
        root = plr;
    return plr;
}

struct node *rr_rotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    pr->height = node_height(pr);
    p->height = node_height(p);
    if (root == p)
        root = pr;

    return pr;
}
struct node *rl_rotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    pr->height = node_height(pr);
    p->height = node_height(p);
    prl->height = node_height(prl);
    if (root == p)
    {
        root = prl;

        return prl;
    }
}

struct node *Rinsert(struct node *p, int key)
{
    struct node *t;

    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->height = 1;
        t->rchild = t->lchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }

    p->height = node_height(p);

    if (balance_factor(p) == 2 && balance_factor(p->lchild) == 1)
    {
        return ll_rotation(p);
    }

    if (balance_factor(p) == 2 && balance_factor(p->lchild) == -1)
    {
        return lr_rotation(p);
    }

    if (balance_factor(p) == -2 && balance_factor(p->lchild) == -1)
    {
        return rr_rotation(p);
    }

    if (balance_factor(p) == -2 && balance_factor(p->lchild) == 1)
    {
        return rl_rotation(p);
    }

    return p;
}
void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

int main()
{
    root = Rinsert(root, 27);
    Rinsert(root, 10);
    Rinsert(root, 20);
    Rinsert(root, 30);
    Rinsert(root, 25);
    Rinsert(root, 28);
    Rinsert(root, 5);

    inorder(root);
    printf("\n");
    printf("height of big tree: %d \n", node_height(root) - 1);
    return 0;
}