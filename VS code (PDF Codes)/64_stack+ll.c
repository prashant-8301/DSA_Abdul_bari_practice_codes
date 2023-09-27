#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(int x){
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
int pop(){
    struct node *p;
    int x = -1;
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

int main(){

push(5);
push(7);
push(8);
push(9);
push(11);
display();
printf("Pop element is : %d \n",pop());
display();
printf("Enter the element number which you want to peek: \n");
int n;
scanf("%d",&n);

printf("Peek element: %d\n",peek(n));
printf("stack empty: %d\n",is_empty());
printf("stack full: %d\n",is_full());

    return 0;
}