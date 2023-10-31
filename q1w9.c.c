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

int main(){

    node *head;
    head = NULL;
    int ans, num, res;
    while(1){
        printf("\nEnqueue 1\nDequeue 2\nDisplay 3\nExit (any button)\n:");
        scanf("%d", &ans);
        if (ans == 1){
            printf("Value to be enqueued: ");
            scanf("%d", &num);
            enqueue(&head, num);
            printf("Equeued: %d\n", num);
        }
        else if(ans == 2){
            res = dequeue(&head);
            printf("Dequeued: %d\n", res);
        }
        else if(ans == 3){
            display(&head);
        }
        else{
            break;
        }
    }

return 0;
}
