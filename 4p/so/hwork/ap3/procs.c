#include "procs.h"


void p123(pid_t pid_consumer) {
  int i;
  while(1) {
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if (sm_f1_ptr->num == 0) {	
      //gen aleatory val bet [1, 1000], inserting into queue
      queue_push(sm_f1_ptr, 1 + (rand() % 1000));
      if(queue_full(sm_f1_ptr)) {
        sm_f1_ptr->num = 1;
        kill(pid_consumer, SIGUSR1);
      }
    }	
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
}


void p4Consumer(int sig) {
  int i;
  int signal;
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGUSR1);
  while(1) {
    sigwait(&set, &signal);
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if (sm_f1_ptr->num == 0) {	
      //gen aleatory val bet [1, 1000], inserting into queue
      if(!queue_push(sm_f1_ptr, 1 + (rand() % 1000))) {
        sm_f1_ptr->num = 1;
      }
    }	
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
}


// p4 need's to access global vars, signal can't pass args
// https://cboard.cprogramming.com/linux-programming/147409-pass-user-parameter-signal-handler-linux.html
void p4(int* p0, int* p1) {
  pthread_t tid;
  pthread_create(&tid, NULL, p4Consumer, NULL);
  p4Consumer();
}