typedef struct queue* Queue;

Queue queue_start();
int queue_empty(Queue);
int queue_push(Queue, int elem);
int queue_pop(Queue, int *elem);