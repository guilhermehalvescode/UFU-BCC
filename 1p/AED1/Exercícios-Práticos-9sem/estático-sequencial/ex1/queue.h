typedef struct queue* Queue;

Queue queue_start();
int queue_empty(Queue);
int queue_full(Queue);
int queue_push(Queue, char *elem);
int queue_pop(Queue, char *elem);