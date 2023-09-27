// why i am not getting the desired output ???? Find the error

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL,*second = NULL,*third = NULL;

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
void create1(int A[], int n)
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
void merge(struct node *first,struct node *second){
struct node *last;
if(first->data<second->data){
     last = third = first;

    first = first->next;
    last->next = NULL;
}
else{
    last = third = second;
    second = second->next;
    last->next = NULL;
}
while(first!=NULL && second!=NULL){
    if(first->data < second->data){
        last = first;
        last->next = NULL;
        first = first->next;
    }
    else{
        last = second;
        last->next = NULL;
        second = second->next;
    }
}
if(first == NULL)
    last->next = second;

else
   last->next = first;
}

int main()
{

    // int A[]={2,3,5,1,6,8,5,9};

    int A[100];
    int n;
    printf("Enter the number of element in your 1st linked list\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the element at position %d :\n", i + 1);
        scanf("%d", &A[i]);
    }

    create(A, n);

    Display(first);

    int B[100];
    int n1;
    printf("Enter the number of element in your 2nd linked list\n");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {
        printf("Enter the element at position %d :\n", i + 1);
        scanf("%d", &B[i]);
    }

    create1(B, n1);
    Display(second);
    merge(first,second);
    Display(third);
    return 0;
}