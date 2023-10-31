#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

void enqueue(node **list, int num){
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("failed");
        return;
    }
    temp->data = num;
    temp->next = NULL;
    if(*list == NULL){
        *list = temp;
    }
    else{
        node *walk;
        walk = (*list);
        while(walk->next != NULL){
            walk= walk->next;
        }
        walk->next = temp;
    }
}

int dequeue(node **list){
    int res;
    if(*list == NULL){
        printf("empty");
    }
    else{
        node *walk;
        walk = (*list);
        (*list) = (*list)->next;
        res = walk->data;
        free(walk);
    }
    return res;
}

void display(node **list){
    node *walk;
    walk = (*list);
    while(walk != NULL){
        printf("%d ", walk->data);
        walk= walk->next;
    }

}

void executer(node **head){
    if(*head == NULL){
        printf("empty");
        return;
    }
    node *list;
    list = (*head)->next;
    node *holder, *fear;
    holder = (*head);
    int keeper;
    while(list!=NULL){
        keeper = holder->data;
        if(keeper == list->data){
            holder->next = list->next;
            fear = list;
            list = list->next;
            free(fear);
            continue;
        }
        list = list->next;
        holder = holder->next;
    }
}

int main(){

    node *h1, *h2, *uwoh, *iwoh;
    h1 = NULL;
    h2 = NULL;
    enqueue(&h1, 1);
    enqueue(&h1, 2);
    enqueue(&h1, 3);
    enqueue(&h1, 3);
    enqueue(&h1, 3);
    enqueue(&h1, 4);
    enqueue(&h1, 4);
    enqueue(&h1, 5);
    printf("before: ");
    display(&h1);
    executer(&h1);
    printf("\nafter: ");
    display(&h1);
    return 0;
}
