#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX 20

struct queue {
    int no[MAX];
    int ini, cont;
};

Queue queue_start() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->ini = 0;
        q->cont = 0;
    }
    return q;
}

int queue_empty(Queue q) {
    return !(q->cont);
}

int queue_full(Queue q) {
    return q->cont == MAX;
}

int queue_push(Queue q, int elem) {
    if(queue_full(q))
        return 0;

    int fim = (q->ini + q->cont) % MAX;
    q->no[fim] = elem;
    (q->cont)++;
    return 1;
}

int queue_pop(Queue q, int *elem) {
    if(queue_empty(q)) 
        return 0;
    *elem = q->no[q->ini];
    q->ini = ((q->ini) + 1) % MAX;
    (q->cont)--;
    return 1;
}