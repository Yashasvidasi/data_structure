#include <stdio.h>
#include <stdlib.h>
#define max 50
#include <string.h>

typedef struct{
    char data[max];
    int top;
}stack;

int isempty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int isfull(stack *s){
    if(s->top == max-1)
        return 1;
    return 0;
}

void push(stack *s, char c){
    if(isfull!=1){
        s->top++;
        s->data[s->top] = c;
    }
    else{
        printf("stack overflow");
    }
}

char pop(stack *s){
    if(isempty!=1){
        return(s->data[s->top--]);
    }
    else{
        printf("stack underflow");
        return;
    }
}

int main(){
    stack s;
    s.top = -1;
    char eq[100];
    gets(eq);
    for(int i = strlen(eq)-1; i>=0; i--){
        switch(eq[i]){
            case '+':
                push(&s, pop(&s)+pop(&s));
                break;
            case '-':
                push(&s, pop(&s)-pop(&s));
                break;
            case '*':
                push(&s, pop(&s)*pop(&s));
                break;
            case '/':
                push(&s, pop(&s)/pop(&s));
                break;
            default:
                push(&s, eq[i] - '0');
                break;

        }
    }
    printf("%d", s.data[s.top]);

}






