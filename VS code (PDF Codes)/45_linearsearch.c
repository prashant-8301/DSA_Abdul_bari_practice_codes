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

struct node *linearsearch(struct node *p,int key){
struct node* q;
q =NULL;
while(p){
    if(p->data==key){
     q->next = p->next;
     p->next = first;
     first = p;
     return p;
    }
    q = p;
    p = p->next;
}

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
    int k;
    printf("Enter the element you want to search\n");
    scanf("%d",&k);
    struct node* f;
    f = linearsearch(first,k);
    printf("Searched element is: %d\n",f->data);
    Display(first);

    return 0;
}