#include <stdio.h>
#include <stdlib.h>
#define max 50
#include <string.h>
#include <ctype.h>

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
    if(isfull(s)!=1){
        s->top++;
        s->data[s->top] = c;
    }
    else{
        printf("stack overflow");
    }
}

char pop(stack *s){
    if(isempty(s)!=1){

        return(s->data[s->top--]);
    }
    else{

        return '\0';
    }
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}



int main(){
    stack s;
    s.top = -1;

    char postfix[100];
    char prefix[100];
    gets(prefix);
    int length = strlen(prefix);
    int j = 0;

    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperator(c)) {
                char operand1 = pop(&s);
                char operand2 = pop(&s);
            if(operand2 != '\0'){
            postfix[j++] = operand1;
            postfix[j++] = operand2;
            postfix[j++] = c;
            }
            else{
                postfix[j++] = operand1;
            postfix[j++] = c;
            }
        } else {
            push(&s, c);
        }
    }

    puts(postfix);
}






