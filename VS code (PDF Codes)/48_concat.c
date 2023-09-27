#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL,*second = NULL,*third =NULL;

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
void create2(int A[], int n)
{
    int i;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = A[0];

    struct node *last, *t;
    second->next = NULL;
    // last->next = NULL;   including this line was not giving any output  // But why is it so??
    last = second;

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

struct node* concat(struct node* p, struct node* q){
    struct node* t,*last;
    last = third;
    // t->next = NULL;
    while(p){
        t = (struct node*)malloc(sizeof(struct node));
        
        t->data = p->data;
        last = t;
        t= t->next;
        last = t;
        p = p->next;
        t->next = NULL;
    }
    while(q){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = q->data;
        q = q->next;
        q->next = NULL;
    }
    return third;
}

int main()
{

    // int A[]={2,3,5,1,6,8,5,9};

    int A[100];
    int n;
    printf("Enter the number of element in your linked list 1\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element at position %d :\n", i + 1);
        scanf("%d", &A[i]);
    }

    create(A, n);
    int B[100];
    int n2;
    printf("Enter the number of element in your linked list 2\n");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++)
    {
        printf("Enter the element at position %d :\n", i + 1);
        scanf("%d", &B[i]);
    }

    create2(B, n2);
    struct node *l;
    Display(first);
    l = concat(first,second);
    Display(l);

    return 0;
}