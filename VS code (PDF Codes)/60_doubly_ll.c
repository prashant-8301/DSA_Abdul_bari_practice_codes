// why this code is not working after i have written the code for delete function?????
// why one warning is coming in the terminal while running this program
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*head = NULL;

// here why when we are creating a doubly linked by passing the head itself then this create function is not creating the doubly linked list

// void create(struct node *p, int A[],int n){
//     struct node *last;
//     p = (struct node*)malloc(sizeof(struct node));
//     p->data = A[0];
//     p->prev = NULL;
//     p->next = NULL;
//     last = p;
    
//     for(int i = 1;i<n;i++){
//         struct node*t;
//         t = (struct node*)malloc(sizeof(struct node));
//         t->data = A[i];
//         t->prev = last;
//         t->next = last->next;
//         last = t;
        
//     }
    
// }
void create(int A[],int n){
    struct node *last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;
        struct node *t;
    
    for(int i = 1;i<n;i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
        
    }
    
}
void display(struct node *p){
    while(p!= NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int count(struct node *p){
    int i = 0;
    while(p){
        i++;
    }
    return i;
}
void insert(struct node *q,int ele,int pos){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = ele;
    if((pos < 1) || (pos> (count + 1))){
        return;
    }
    else if(pos == 1){
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else{
        // struct node *q;
        // q = head;
        for(int i = 0;i<(pos-2);i++){
            q = q->next;
        }
        t->next = q->next;
        t->prev = q;
        q->next = t;
    }
}
int delete(struct node *p,int del_pos){
    int x;
if(del_pos < 1 || del_pos > count) {
    return -1111;
}
else if( del_pos == 1){
    head = head->next;
    if(head)
    head->prev = NULL;

    x = p->data;
    free(p);
  
}
else{
    struct node *q;
    for(int i = 0;i<del_pos-1;i++){
        q = p;
        p = p->next;
    }
    q->next = p->next;
    if(p->next)
    p->next->prev = q;
    x = p->data;
    free(p);
    
}

return x;
}


int main(){
     int x;
    int A[100];
    printf("Enter the total number of element present in your circular linked list\n");
    scanf("%d", &x);
    printf("Enter the the element which you want to add in circular linked list\n");
    for (int i = 0; i < x; i++)
    {
        printf("Position %d element: \n", i + 1);
        scanf("%d", &A[i]);
    }
    create(A,x);
    display(head);
    printf("Enter the elment and its position to insert: \n");
    int ele;
    int pos;
    scanf("%d %d",&ele,&pos);
    insert(head,ele,pos);
    display(head);
    printf("Enter the position of the element which you want it to delete: \n");
    int del_pos;
    scanf("%d",&del_pos);
    printf("The deleted element is : %d \n",delete(head,del_pos));
    display(head);
    return 0;
}