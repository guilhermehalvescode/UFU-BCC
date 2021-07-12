#include <stdlib.h>
#include "simpleQueue.h"

struct node {
    int info;
    struct node* next;
};

struct queue {
    struct node* start;
    struct node* end;
};

Queue queue_start() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->start = NULL;
        q->end = NULL;
    }
    return q;
}

int queue_empty(Queue q) {
    return q->start == NULL;
}

int queue_push(Queue q, int elem) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    if(n == NULL) 
        return 0;
    n->info = elem;
    n->next = NULL;
    if(queue_empty(q)) {
        q->start = n;
    } else {
        (q->end)->next = n;
    }
    q->end = n;
    return 1;
}

int queue_pop(Queue q, int *elem) {
    if(queue_empty(q)) 
        return 0;
    struct node* aux = q->start;
    *elem = aux->info;
    if(q->start == q->end) 
        q = NULL;
    q->start = aux->next;
    free(aux);
    return 1;
}