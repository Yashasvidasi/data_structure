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

int getp(char ch){
    char c[] = {'+','-','*','/',')',};
    int p[] = {1,1,2,2,0};
    for(int i = 0; i<5; i++){
        if(c[i] == ch){
            return (p[i]);
        }
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(){
    stack s, post;
    s.top = -1;
    post.top = -1;
    char eq[100], car;
    gets(eq);
    for(int i = strlen(eq)-1; i>=0; i--){
        if(isOperator(eq[i])){
                if(s.top != -1){
                    while(getp(eq[i])<=getp(s.data[s.top]) && s.top != -1){
                        push(&post, pop(&s));
                    }
                }
                push(&s, eq[i]);
                continue;

        }
        switch(eq[i]){
            case '(':
                car = 'a';
                while(car != ')'){
                        car = pop(&s);
                        if (car == ')')
                            break;
                        push(&post, car);
                      }
                break;
            case ')':
                push(&s, eq[i]);
                break;
            default:
                push(&post, eq[i]);
                break;

        }
    }

    while(s.top>-1){
        push(&post, pop(&s));
    }
    while(post.top >-1){
        printf("%c", pop(&post));
    }
}







