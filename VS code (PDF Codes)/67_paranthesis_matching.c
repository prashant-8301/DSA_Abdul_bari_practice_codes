#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(char x){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(t == NULL){
        printf("stack is full\n");
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
void display(){
    struct node *p;
    p = top;
    while(p!= NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
char pop(){
    struct node *p;
    char x = -1;
    p = top;
    if(top == NULL){
        printf("stack is empty\n");
    }
    else{
        x = p->data;
        top = top->next;
        free(p);
    }
    return x;
}
int peek(int n){
    struct node *p;
    
    p = top;
    if(top == NULL){
        return -1;
    }
    else{
        for(int i = 0; i<(n-1)&& p!=NULL;i++){
        p = p->next;
        }
     
     return p->data;
    }
}
int is_empty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    int r = t?0:1;
    free(t);
    return r;
}
int isBalanced(char *exp){
    int i;
    for(i=0;exp[i]!= '\0';i++){
        if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] ==')'){
            if(top == NULL){
                return 0;
            }
            pop();
        }
    }
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

char *exp = "((a+b)*(c-d)";
printf("%d",isBalanced(exp));

    return 0;
}