#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include "sharedmems.h"
#include <stdio.h>

void queue(Queue q);

void* gen_shared_area(key_t sm_key, int isF1) {
  if(sm_key < 0) return NULL;
  int shmid;
	void *sm = NULL;

  if ((shmid = shmget(sm_key, isF1 ? MEM_SZ_F1 : MEM_SZ_F2, 0666|IPC_CREAT)) == -1) {
    printf("err: %d", errno);
		return NULL;
  }
  //shr_mem attach
	if ((sm = shmat(shmid, NULL, 0)) == (void *) -1)
		return NULL;
  // gen f1 or f2 starting it's queue

  if(isF1) {
    //casting to f1 and initializing
    Shared_area_f1 f1 = (Shared_area_f1) sm;
    queue(&f1->queue);  
    //set consumer pid negative for initilization
    f1->consumer_pid = -1;
    f1->num = 0;
  } else {
    //casting to f2 and initializing
    int i;
    Shared_area_f2 f2 = (Shared_area_f2) sm;
    queue(&f2->queue);  
    f2->counter = 0;
    f2->p56qnt = 0;
    for(i = 0; i < MAX_RANGE; i++) f2->reps[i] = 0;
  }
  return sm;
}

// start queue
void queue(Queue q) {
  if(q) {
    q->cont = 0;
    q->ini = 0;
  }
}

// check queue full
int queue_full(Queue q) {
  return q->cont == MAX;
}

// check queue empty
int queue_empty(Queue q) {
  return !q || !(q->cont);
}

// push value to queue
int queue_push(Queue q, int value) {
  if(queue_full(q)) return 0;
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
