#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAX 20

struct queue {
    char no[MAX][11];
    int ini, fim;
};

Queue queue_start() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->ini = 0;
        q->fim = 0;
    }
    return q;
}

int queue_empty(Queue q) {
    return q->ini == q->fim;
}

int queue_full(Queue q) {
    return q->ini == ((q->fim) + 1) % MAX;
}

int queue_push(Queue q, char *elem) {
    if(queue_full(q) || strlen(elem) > 10)
        return 0;
    strcpy(q->no[q->fim], elem);
    q->fim = ((q->fim) + 1) % MAX;
    return 1;
}

int queue_pop(Queue q, char *elem) {
    if(queue_empty(q)) 
        return 0;
    strcpy(elem, q->no[q->ini]);
    q->ini = ((q->ini) + 1) % MAX;
    return 1;
}