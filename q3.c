#include <stdio.h>
#include <stdlib.h>
#define max 50
#include <string.h>

typedef struct{
    int data[100];
    int top1, top2;
}stack;

int isempty(stack *s){
    if(s->top1 == 50 || s->top2 == 51)
        return 1;
    return 0;
}

int isfull(stack *s){
    if(s->top1 == 0 || s->top2 == 99)
        return 1;
    return 0;
}

void push1(stack *s, int c){
    if(isfull!=1){
        s->top1++;
        s->data[s->top1] = c;
    }
    else{
        printf("stack overflow");
    }
}
void push2(stack *s, int c){
    if(isfull!=1){
        s->top2--;
        s->data[s->top2] = c;
    }
    else{
        printf("stack overflow");
    }
}

int pop1(stack *s){
    if(isempty(s)!=1){
        return(s->data[s->top1--]);
    }
    else{
        printf("stack underflow");
        return -1;
    }
}
int pop2(stack *s){
    if(isempty(s)!=1){
        return(s->data[s->top2++]);
    }
    else{
        printf("stack underflow");
        return -1;
    }
}

int main(){
    stack s;
    s.top1 =50;
    s.top2 = 51;
    push1(&s, 1);
    push1(&s, 2);
    push2(&s, 3);
    printf("%d ",pop1(&s));
    printf("%d ",pop2(&s));
    printf("%d ",pop2(&s));
    return 0;

}







