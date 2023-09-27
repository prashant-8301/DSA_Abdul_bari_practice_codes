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
int delete(struct node *p,int n,int k){
   struct node *last;
   last = first;
   p = p->next;
   for(int i = 0;i<k-2;i++){
       p = p->next;
       last = last->next;
   }
   int x;
   x = p->data;
   last->next = p->next;
   free(p);
   return x;

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

    Display(first);
    int k;
    printf("Enter the position of element which you want it to be deleted\n");
    scanf("%d",&k);
    int x = delete(first,n,k);
    printf("Deleted data is = %d\n",x);
    Display(first);


    return 0;
}