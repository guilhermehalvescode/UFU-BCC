#include <stdlib.h>
#include "queue.h"
struct node {
    int info;
    struct node* next;
};

Queue queue_start() {
    return NULL;
}

int queue_empty(Queue q) {
    return q == NULL;
}

int queue_push(Queue *q, int elem) {
    Queue node = (Queue) malloc(sizeof(struct node));
    if(node == NULL) 
        return 0;
    node->info = elem;
    if(queue_empty(*q)) {
        node->next = node;
        *q = node;
    } else {
        node->next = (*q)->next;
        (*q)->next = node;
        *q = node;
    }
    return 1;
}

int queue_pop(Queue *q, int *elem) {
    if(queue_empty(*q)) 
        return 0;
    Queue aux = (*q)->next;
    *elem = aux->info;
    if(*q == (*q)->next) 
        *q = NULL;
    else
        (*q)->next = aux->next;
    free(aux);
    return 1;
}