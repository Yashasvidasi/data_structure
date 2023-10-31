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
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}


void enqueue_rear(node **list, int num){
    node *temp = create();
    temp->data = num;
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
        temp->prev = walk;
    }
}

void enqueue_front(node **list, int num){
    node *temp = create();
    temp->data = num;
    temp->next = (*list);
    (*list) = temp;
}

int dequeue_front(node **list){
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

int dequeue_rear(node **list){
    int res;
    if(*list == NULL){
        printf("empty");
    }
    else{
        node *walk, *hold;
        walk = (*list);
        while(walk->next != NULL){
            hold = walk;
            walk= walk->next;
        }
        hold->next = NULL;
        free(walk);
        res = hold->data;
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

int main(){

    node *head;
    head = NULL;
    int ans, num, res;
    while(1){
        printf("\nEnqueue rear 1\nDequeue rear 2\nEnqueue Front 3\nDequeue Front 4\nDisplay 5\nExit (any button)\n:");
        scanf("%d", &ans);
        if (ans == 1){
            printf("Value to be enqueued: ");
            scanf("%d", &num);
            enqueue_rear(&head, num);
        }
        else if(ans == 3){
            res = dequeue_rear(&head);
            printf("Dequeued: %d\n", res);
        }
        else if(ans == 2){
            printf("Value to be enqueued: ");
            scanf("%d", &num);
            enqueue_front(&head, num);
        }
        else if(ans == 4){
                res = dequeue_front(&head);
            printf("Dequeued: %d\n", res);
        }
        else if(ans == 5){
            display(&head);
        }
        else{
            break;
        }
    }

return 0;
}
