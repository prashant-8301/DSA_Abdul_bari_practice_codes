#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *s;
};

int pre(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}
void push(struct stack *st, char x)
{
    if (st->top == (st->size - 1))
    {
        printf("stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else
        return 1;
}
int pop(struct stack *st)
{
    char t;
    if (st->top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        t = st->s[st->top];
        st->top--;
        return t;
    }
}

char *IntoPost(char *infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));
    int i = 0, j = 0;
    struct stack st;
    st.size = len + 1;
    st.top = -1;
    st.s = (char *)malloc((len + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if ((pre(infix[i]) > pre(st.s[st.top])) || (st.top == -1))
        {
            push(&st, infix[i++]);
        }
        else
        {
            postfix[j++] = pop(&st);
        }
    }
    while (st.top != -1)
    {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}
int eval(char *postfix){
    struct stack st;
    int i , x1, x2, r;
    for(i = 0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i]))
        push(&st,postfix[i]-'0');
        else{
            x2 = pop(&st);x1 = pop(&st);
            switch(postfix[i]){
                case '-' : r = x1 - x2; break;
                case '+' : r = x1 + x2; break;
                case '*' : r = x1 * x2; break;
                case '/' : r = x1 / x2; break;
            }
            push(&st,r);
        }
    }
}

int main()
{
    char *infix = "35*62/+4-";
    char *postfix = IntoPost(infix);
    printf("%s\n", postfix);
    printf("Evaluation of postfix expression is : %d\n",eval(postfix));

    return 0;
}