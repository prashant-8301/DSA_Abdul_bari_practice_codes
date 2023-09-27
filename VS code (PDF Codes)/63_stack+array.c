#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};
void create(struct stack *st){
printf("Enter the total size of your stack : \n");
scanf("%d",&st->size);
st->top = -1;
st->s = (int *)malloc(st->size*sizeof(int));

}
void push(struct stack *st, int x){
    if(st->top == st->size -1){
        printf("stack overflow\n");
    }
    else{
    st->top++;
    st->s[st->top] = x;
    }
}
void pop(struct stack *st){
    if(st->top == -1){
        printf("stack underflow\n");
    }
    else{
        printf("pop out element : %d\n",st->s[st->top]);
        st->top--;
    }
}
void display(struct stack st){
    for(int i = st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
    printf("\n");
}
int peek(struct stack st,int pos){
    int x = -1;
    if((st.top - pos +1) < 0){
        printf("stack underflow\n");
    }
    else{
        x = st.s[st.top - pos + 1];
    }
    return x;
}
int is_empty(struct stack st){
    if(st.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(struct stack st){
    if(st.top == (st.size - 1)){
        return 1;
    }
    else{
        return 0;
    }
}
int stack_top(struct stack st){
    if(st.top == -1){
     return -1;
    }
    else{
        return st.s[st.top];
    }
}
int main(){
    
    struct stack st;

 
create(&st);
push(&st,2);
push(&st,5);
push(&st,9);
push(&st,15);
display(st);
pop(&st);
display(st);
int pos;
printf("Enter the serial number of element which you want to peek: \n");
scanf("%d",&pos);
printf("Peek element: %d\n",peek(st,pos));
printf("Empty : %d\n",is_empty(st));
printf("Full : %d\n",is_full(st));
printf("stack top : %d\n",stack_top(st));

    return 0;
}