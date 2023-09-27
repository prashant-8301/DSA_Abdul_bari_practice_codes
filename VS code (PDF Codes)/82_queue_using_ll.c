#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front = NULL,*rear = NULL;

void enqueue(int x){
    
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(t == NULL){
        printf("Queue is full\n");

    }
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }

}
int dequeue(){
    int x = -1;
    struct node *p;
    if(front == NULL){
        printf("Queue is empty");
    }
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}
void display(){
    struct node *p;
    p = front;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");

}

int main(){
enqueue(8);
enqueue(9);
enqueue(10);
enqueue(11);
printf("deleted element : %d \n",dequeue());
display();

    return 0;
}