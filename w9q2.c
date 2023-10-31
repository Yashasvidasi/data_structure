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

node* union_without_head(node **h1, node **h2){
    node *unified;
    unified = NULL;
    node *walk, *innerwalk;
    walk = (*h1);
    while(walk != NULL){
        enqueue(&unified, walk->data);
        walk= walk->next;
    }
    walk = (*h2);
    int c;
    innerwalk = unified;
    while(walk != NULL){
        c = 0;
        while(innerwalk != NULL){
            if(walk->data == innerwalk->data)
                c = 1;
            innerwalk = innerwalk->next;
        }
        if(c == 0)
            enqueue(&unified, walk->data);
        walk= walk->next;
        innerwalk = unified;
    }
    return unified;
}

node* union_with_head(node **h1, node **h2){
    node *unified;
    unified = NULL;
    node *walk, *innerwalk;
    walk = (*h1)->next;
    while(walk != NULL){
        enqueue(&unified, walk->data);
        walk= walk->next;
    }
    walk = (*h2)->next;
    int c;
    innerwalk = unified;
    while(walk != NULL){
        c = 0;
        while(innerwalk != NULL){
            if(walk->data == innerwalk->data)
                c = 1;
            innerwalk = innerwalk->next;
        }
        if(c == 0)
            enqueue(&unified, walk->data);
        walk= walk->next;
        innerwalk = unified;
    }
    return unified;
}

node* intersect_without_head(node **h1, node **h2){
    node *unified, *innerwalk, *walk;
    unified = NULL;
    innerwalk = (*h2);
    walk = (*h1);
    while(walk != NULL){
        while(innerwalk != NULL){
            if(walk->data == innerwalk->data){
                enqueue(&unified, walk->data);
                break;
            }
            innerwalk = innerwalk->next;
        }
        walk= walk->next;
        innerwalk = (*h2);
    }
    return unified;
}

node* intersect_with_head(node **h1, node **h2){
    node *unified, *innerwalk, *walk;
    unified = NULL;
    innerwalk = (*h2)->next;
    walk = (*h1)->next;
    while(walk != NULL){
        while(innerwalk != NULL){
            if(walk->data == innerwalk->data){
                enqueue(&unified, walk->data);
                break;
            }
            innerwalk = innerwalk->next;
        }
        walk= walk->next;
        innerwalk = (*h2)->next;
    }
    return unified;
}




int main(){

    node *h1, *h2, *uwoh, *iwoh;
    h1 = NULL;
    h2 = NULL;
    enqueue(&h1, 1);
    enqueue(&h1, 2);
    enqueue(&h1, 3);
    enqueue(&h1, 4);
    enqueue(&h2, 1);
    enqueue(&h2, 2);
    enqueue(&h2, 5);
    enqueue(&h2, 6);
    printf("\nlist 1:");
    display(&h1);
    printf("\nlist 2:");
    display(&h2);
    uwoh = union_without_head(&h1, &h2);
    printf("\n\nunion without head:");
    display(&uwoh);
    iwoh = intersect_without_head(&h1, &h2);
    printf("\nintersection without head:");
    display(&iwoh);
    uwoh = union_with_head(&h1, &h2);
    printf("\n\nunion with head:");
    display(&uwoh);
    iwoh = intersect_with_head(&h1, &h2);
    printf("\nintersection with head:");
    display(&iwoh);
    printf("as we consider 1st node as head 1 will be discarded from either list\n");


return 0;
}

