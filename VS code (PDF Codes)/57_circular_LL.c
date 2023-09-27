#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int A[], int n)
{
    head = (struct node *)malloc(sizeof(struct node));
    struct node *last;
    head->data = A[0];
    last = head;
    last->next = NULL;
    for (int i = 1; i < n; i++)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        last->next = t;
        last = t;
    }
    last->next = head;
}
void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}
int length(struct node *p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p!= head);
    return len;
}
void insert(struct node *p,int index,int data){
    struct node*q;
    q = NULL;
    struct node* t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    if(index<=0 || index>length(head)+1){
        return;
    }
    else{
        if(index == 1 || index == length(head)+1){
            while(p->next!=head) p = p->next;
            p->next = t;
            t->next = head;
            head = t;
            
        }
        else{
            for(int i = 0;i<index-1;i++){
                q = p;
                p = p->next;
            }
            q->next = t;
            t->next = p;
        }
    }
}
int delete(struct node *p,int index){
    struct node *q;
    q = NULL;
    int x;
    for(int i = 0;i<index-1;i++){
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;

}

int main()
{
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
    create(A, x);
    display(head);
    printf("The length of the given circular linked list is : %d\n",length(head));
    printf("Enter the respective index and data of the new node which you want to insert: \n");
    int index , data;
    scanf("%d",&index);
    scanf("%d",&data);
    insert(head,index,data);
    display(head);
    printf("Enter the respective index of the node which you want to delete: \n");
    int del_index;
    scanf("%d",&del_index);
    printf("The deleted element is : %d \n",delete(head,del_index));
    display(head);


    return 0;
}