#include<stdio.h>
#include<stdlib.h>
#include"91_Queue.c"

void preorder(node*t){
    struct stack st;
    while(t! = NULL || !isempty(st)){
        if(t!=NULL){
            printf("%d ",t->data);
            push(&st,t);
            t = t->lchild;
        }
        else{
            t = pop(&st);
            t = t->rchild;
        }
    }
}
void inorder(node *t){
    struct stack st;
    while(t!=NULL || isempty(st)){
        if(t!=NULL){
            push(&st,t);
            t = t->lchild;
        }
        else{
            t = pop(&st);
            printf("%d ",t->data);
            t = t->rchild;
        }
    }
}

int main(){

    return 0;
}