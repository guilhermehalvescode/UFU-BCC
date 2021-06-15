typedef struct queue* Queue;

Queue queue_start();
int queue_empty(Queue);
int queue_full(Queue);
int queue_push(Queue, int mat, char *name, int faults, float media);
int queue_pop(Queue, int *mat, char *name, int *faults, float *media);