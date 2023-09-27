// Find why you are not able to complete this code

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(char c){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack is full\n");

    }
    else{
        t->data = c;
        t->next = NULL;
        top = t;

    }

}
int main(){
struct stack *infix;
// create(&infix);  no need to "create" the stack using linked list
printf("Enter the total number of element present in your expression\n");
int n;
scanf("%d",&n);
printf("Enter the element of your expression\n");
char c;
for(int i = 0;i<n;i++){
    
    scanf("%c",&c);
    push(c);
}

    return 0;
}