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
    // last->next = NULL;   including this line was not giving any output  // But why is it so??
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
void Display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
insert_in_sorted_LL(struct node *p,int x){
    struct node *q,*t;
    t = NULL;
    q = (struct node *)malloc(sizeof(struct node));
    q->data = x;
    while(p->data < x){
        t = p;
        p = p->next;
    }
    t->next = q;
    q->next = p;
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

    Display(first);
    int x;
    printf("Enter the number which you want it to insert\n");
    scanf("%d",&x);
    insert_in_sorted_LL(first,x);
    Display(first);
    return 0;
}