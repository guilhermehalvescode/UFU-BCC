#include <stdlib.h>
#include "staticqueue.h"
#define MAX 10

// static queue with counter
struct queue {
  int queue[MAX], ini, cont;
};

// start queue
Queue queue() {
  Queue q = (Queue) malloc(sizeof(struct queue));
  if(q) {
    q->cont = 0;
    q->ini = 0;
  }
  return q;
}

// check queue full
int queue_full(Queue q) {
  return q->cont == MAX;
}

// check queue empty (returns true if not created)
int queue_empty(Queue q) {
  return !q || !(q->cont);
}

// push value to queue
int queue_push(Queue q, int value) {
  if(!q || queue_full(q)) return 0;
  q->queue[(q->ini + q->cont) % MAX] = value;
  (q->cont)++;
  return 1;
}

// pop value from queue
int queue_pop(Queue q, int *value) {
  if(queue_empty(q)) return 0;
  *value = q->queue[q->ini];
  q->ini = (q->ini + 1) % MAX;
  (q->cont)--;
  return 1;
}
