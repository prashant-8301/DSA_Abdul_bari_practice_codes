#include <stdio.h>
#include <stdlib.h>
#include "91_Queue.c"

struct node *root = NULL;

void treecreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    printf("Enter root value\n");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
   /* here we allocated only one binary tree if we allocated mor   one binary tree than this would have been the case of 2D st   of binary in q->Q. and then we would have called any parti   binary tree by writing || (*q).*(*(Q + 4) + 2) || like this.*/
       root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("enter left child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
         t = (struct node *)malloc(sizeof(struct node));
         t->data = x;
         t->lchild = t->rchild = NULL;
         p->lchild = t;
         enqueue(&q,t);
        }
        printf("Enter right child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
    }
}
void preorder(struct node*p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder("p->rchild");
    }
}
void postorder(struct node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void levelorder(struct node *p){
    struct queue q;
    create(&q,100);

    printf("\n%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        // printf("%d ",p->data);
        if(p->lchild){
          printf("%d ",p->lchild->data);
          enqueue(&q,p->lchild);
        }
        if(p->rchild){
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int count(struct node *root){
    if(root){
        return count(root->lchild) + count(root->rchild) + 1;
    }
    else{
        return 0;
    }
}
int height(struct node *root){
    int x = 0;
    int y = 0;
    if(!root){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y)
    return x + 1;
    else
    return y + 1;
    
}

int main()
{
    treecreate();
    preorder(root);
    printf("\n Post order ");
    postorder(root);
    levelorder(root);
    printf("\nCount %d \n",count(root));
    printf("Height %d \n",height(root));

    return 0;
}
// Queue Header file

