#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;


node *create(){
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("failed");
        return;
    }
    temp->prev = temp;
    temp->next = temp;
    return temp;
}

void enqueue_front(node **list, int num){
    node *temp = create();
    temp->data = num;
    ((*list)->next)->prev = temp;
    temp->next = ((*list)->next);
    (*list)->next = temp;
    temp->prev = (*list);

}

void display(node **list){
    node *walk;
    walk = (*list)->next;
    while(walk != (*list)){
        printf("%d", walk->data);
        walk= walk->next;
    }

}

void addition(node **l1, node **l2){
    int c = 0;
    int v = 0;
    node *walk1, *walk2, *walk3;
    walk3 = create();
    walk1 = (*l1)->prev;
    walk2 = (*l2)->prev;
    while(walk1 != (*l1) && walk2 != (*l2)){
        v = (walk1->data + walk2->data);
        v = v+c;
        c = 0;
        if(v>9){
            v = v%10;
            c = 1;
        }
        enqueue_front(&walk3, v);
        walk1 = walk1->prev;
        walk2 = walk2->prev;
    }
    if(walk1 == (*l1) && walk2 != (*l2)){

        while(walk2 != (*l2)){
        v = (walk2->data)+c;
        c = 0;
        if(v>9){
            v = v%10;
            c = 1;
        }
        enqueue_front(&walk3, v);
        walk2 = walk2->prev;
        }
    }
    else if(walk2 == (*l2) && walk1 != (*l1)){

        while(walk1 != (*l1)){
            v = (walk1->data)+c;
            c = 0;
            if(v>9){
                v = v%10;
                c = 1;
        }
        enqueue_front(&walk3, v);
        walk1 = walk1->prev;
        }
    }
    if(c==1){
        enqueue_front(&walk3, 1);
    }
    display(&walk3);
}

node *convert(int n){
    int r;
    node *h = create();
    while(n>=1){
        r = n%10;
        n = (int)n/10;
        enqueue_front(&h, r);
    }
    return h;

}

int main(){
    node *h1;
    node *h2;
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    h1 = convert(num1);
    h2 = convert(num2);
    addition(&h1, &h2);
    return 0;

return 0;
}

