#include <stdlib.h>
#include <sys/shm.h>

#include "staticqueue.h"
#define MEM_SZ sizeof(struct shared_area)
#define MAX 10

// static queue on shared mem with counter
struct queue {
  int queue[MAX], ini, cont;
};

void queue(Shared_area shared_mem);
typedef struct queue* Queue;

Shared_area gen_shared_queue_area(key_t sm_key) {
  if(sm_key < 0) return NULL;
  int shmid;
	void *sm = NULL;
  if ((shmid = shmget(sm_key, MEM_SZ, 0666|IPC_CREAT)) == -1)
		return NULL;
  //shr_mem attach
	if ((sm = shmat(shmid, NULL, 0)) == (void *) -1 )
		return NULL;
  //start queue
  queue((Shared_area) sm);
  return (Shared_area) sm;
}

// start queue
void queue(Shared_area shared_mem) {
  if(!shared_mem) return;
  Queue q = &shared_mem->queue;
  if(q) {
    q->cont = 0;
    q->ini = 0;
  }
}

// check queue full
int queue_full(Shared_area shared_mem) {
  if(!shared_mem) return;
  Queue q = &shared_mem->queue;
  return q->cont == MAX;
}

int queue_full_q(Queue q) {
  return q->cont == MAX;
}

// check queue empty
int queue_empty(Shared_area shared_mem) {
  if(!shared_mem) return;
  Queue q = &shared_mem->queue;
  return !(q->cont);
}

int queue_empty_q(Queue q) {
  return !q || !(q->cont);
}


// push value to queue
int queue_push(Shared_area shared_mem, int value) {
  if(!shared_mem) return;
  Queue q = &shared_mem->queue;
  if(queue_full(q)) return 0;
  q->queue[(q->ini + q->cont) % MAX] = value;
  (q->cont)++;
  return 1;
}

// pop value from queue
int queue_pop(Shared_area shared_mem, int *value) {
  if(!shared_mem) return;
  Queue q = &shared_mem->queue;
  if(queue_empty_q(q)) return 0;
  *value = q->queue[q->ini];
  q->ini = (q->ini + 1) % MAX;
  (q->cont)--;
  return 1;
}
