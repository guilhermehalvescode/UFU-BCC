#include "procs.h"
#include <stdlib.h>
#include <stdio.h>

int p4IsConsuming = 0;
struct args {
  Shared_area sm_f1_ptr; 
  int* pipe;
};

void p123(Shared_area sm_f1_ptr, int id) {
  int i, aleNum;
  while(1) {
    //1, 2, 3 waiting for p4 to set it's pid for signaling
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if (sm_f1_ptr->consumer_pid != -1 && sm_f1_ptr->num == 0) {	
      //gen aleatory val bet [1, 1000], inserting into queue
      aleNum = 1 + (rand() % 1000);
      queue_push(sm_f1_ptr, aleNum);
      printf("Pid-P123: %d gerou aleNum(%d)\n", id, aleNum);
      if(queue_full(sm_f1_ptr)) {
        sm_f1_ptr->num = 1;
        kill(sm_f1_ptr->consumer_pid, SIGUSR1);
      }
    }	
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
}


void* p4Consumer(void* args) {
  int i;
  int signal, value;
  Shared_area sm_f1_ptr = ((struct args*) args)->sm_f1_ptr;
  int* pipe = ((struct args*) args)->pipe;
  while(1) {
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if(p4IsConsuming) {
      queue_pop(sm_f1_ptr, &value);
      if(!queue_empty(sm_f1_ptr)) {
        printf("got %d from f1\n", value);
        sleep(2);
        // send through pipe (value)
      } else {
        printf("queue empty\n");
        // queue empty,
        p4IsConsuming = 0;
        sm_f1_ptr->num = 0;
      }
    }  
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
}

void p4Handler() {
  p4IsConsuming = 1;
}

// p4 need's to access global vars, signal can't pass args
// https://cboard.cprogramming.com/linux-programming/147409-pass-user-parameter-signal-handler-linux.html
void p4(Shared_area sm_f1_ptr, int* pipe0, int* pipe1) {
  sem_wait((sem_t *) &sm_f1_ptr->mutex);
  // put p4 pid on shared mem to p123 signaling
  sm_f1_ptr->consumer_pid = getpid();
  sem_post((sem_t *) &sm_f1_ptr->mutex);
  signal(SIGUSR1, p4Handler);
  pthread_t tid;
  struct args args_t1 = {sm_f1_ptr, pipe0};
  struct args args_t2 = {sm_f1_ptr, pipe1};
  pthread_create(&tid, NULL, p4Consumer, (void*) &args_t1);
  p4Consumer((void*) &args_t2);
}