// Why this code is not giving the correct output?????? Find the reason     --- > Solved :)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];

    struct node *last, *t;
    first->next = NULL;
 
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        last->next = t;
        last = t;
        last->next = NULL;
    }
}

int delete(struct node *p,int pos,int n){
struct node *q;

int x;
if(pos<0||pos>n){
    return -1;
}
if(pos==1){
    q = first;
    x = q->data;
    first = first->next;
    free(q);
    return x;
}
else{
    q = NULL;
    
for(int i = 0;i<pos-1;i++){
    q = p;
   p = p->next;
}
q->next = p->next;
x = p->data;
free(p);
return x;
}
}

void Display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

}

int main()
{
    // int A[]={2,3,5,1,6,8,5,9};

    int A[100];
    int n;
    printf("Enter the number of element in your linked list\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element at position %d :\n", i + 1);
        scanf("%d", &A[i]);
    }
    create(A, n);
    int pos;
    printf("Enter the position where you want to delete\n");
    scanf("%d",&pos);
    int k = delete(first,pos,n);

    Display(first);
    printf("Deleted data %d\n",k);
    return 0;
}