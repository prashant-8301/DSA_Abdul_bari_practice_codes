#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;

void insert(int key){
struct node *t = root;
struct node *r,*p;

if(root==NULL){
    p = (struct node *)malloc(sizeof(struct node));
    p->lchild = p->rchild = NULL;
    p->data = key;
    root = p;
    return; // here we don't have to write else because here return is there inside this if statement
}
while(t!=NULL){
    r=t;
    if(key<t->data){
        t = t->lchild;
    }
    else if(key>t->data){
        t = t->rchild;
    }
    else{
        return;
    }
}
 p = (struct node *)malloc(sizeof(struct node));
    p->lchild = p->rchild = NULL;
    p->data = key;
    if(key>r->data){
        r->rchild = p;
    }
    else{
        r->lchild = p;
    } 
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
struct node *search(int key){
    struct node *t = root;
    while(t!=NULL){
        if(key==t->data)
        return t;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}

struct node *Rinsert(struct node *p,int key){
    struct node *t;
    if(p == NULL){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
      p->lchild = Rinsert(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Rinsert(p->rchild,key);
    }
    return p;
}
struct node *inpre(struct node *p){
while(p&&p->rchild!=NULL)
p = p->rchild;
return p;
}

struct node *insucc(struct node*p){
    while(p&&p->lchild!=NULL)
    p = p->lchild;
    return p;
}

int height(struct node *p){
    int x,y;
    if(p==NULL)return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y?x+1:y+1;
}
struct node* delete(struct node*p,int key){
    struct node *q;
    if(p==NULL)
    return NULL;
    if((p->lchild == NULL) && (p->rchild == NULL)){
        if(p==root)
        root = NULL;

        free(p);
        return NULL;

    }
    
    if(key < p->data)
    p->lchild = delete(p->lchild, key);
    else if(key>p->data)
    p->rchild = delete(p->rchild,key);
    else{
        if(height(p->lchild)>height(p->rchild)){
            q = inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete(p->lchild,q->data);
        }
        else{
            q = insucc(p->rchild);
            p->data = q->data;
            p->rchild = delete(p->rchild,q->data);
        }
    }
    return p;
}

 
int main(){
    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);
    root = Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);
    delete(root,10);

    inorder(root);
    printf("\n");
    struct node *temp;
    temp = search(20);
    if(temp){
        printf("\n %d element is found \n",temp->data);
    }
    else
    printf("Element is not found\n");


    return 0;
}
