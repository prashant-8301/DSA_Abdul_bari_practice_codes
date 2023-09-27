// Why eval function didn't ran here in this code
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
}*poly = NULL;

void create(){
struct node *t,*last = NULL;
int num;
printf("Enter the total number of terms in your polynomial expression \n");
scanf("%d",&num);
printf("Enter the coefficient and power of each term one by one : \n");
for(int i = 0;i<num;i++){
    t = (struct node*)malloc(sizeof(struct node));
    scanf("%d%d",&t->coeff,&t->exp);
    if(poly == NULL){
        poly = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

}

void display(){
    struct node *p;
    p = poly;
    while(p){
        printf("%dX%d ",p->coeff,p->exp);
        p = p->next;
    }
    printf("\n");
}
void eval(int x){
    struct node *p;
    p = poly;
    double sum = 0;
    while(p){
        sum = sum + (p->coeff)*(pow(x,p->coeff));
    }
    printf("The sum of the given polynomial expression is: %d\n",sum);
}

int main(){

create();
display();
eval(1);

    return 0;
}