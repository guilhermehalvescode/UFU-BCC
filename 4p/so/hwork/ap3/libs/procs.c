#include "procs.h"

int p4IsConsuming = 0;
int counter, reps[MAX_RANGE]; // p7 statistics

struct args {
  Shared_area_f1 sm_f1_ptr; 
  int pipe;
};

void p123(Shared_area_f1 sm_f1_ptr) {
  int i, aleNum;
  while(1) {
    //1, 2, 3 waiting for p4 to set it's pid for signaling
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if (sm_f1_ptr->consumer_pid != -1 && sm_f1_ptr->num == 0) {	
      //gen aleatory val bet [1, 1000], inserting into queue
      aleNum = 1 + (rand() % MAX_RANGE);
      queue_push(&sm_f1_ptr->queue, aleNum);
      if(queue_full(&sm_f1_ptr->queue)) {
        sm_f1_ptr->num = 1;
        kill(sm_f1_ptr->consumer_pid, SIGUSR1);
      }
    }	
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
}


void* p4Consumer(void* args) {
  int i, signal, value;
  int pipeEntrance = ((struct args*) args)->pipe;
  Shared_area_f1 sm_f1_ptr = ((struct args*) args)->sm_f1_ptr;
  int pipe = ((struct args*) args)->pipe;
  while(1) {
    sem_wait((sem_t *) &sm_f1_ptr->mutex);
    if(p4IsConsuming) {
      queue_pop(&sm_f1_ptr->queue, &value);
      if(!queue_empty(&sm_f1_ptr->queue)) {
        // send through pipe (value)
        write(pipeEntrance, &value, sizeof(int));
      } else {
        // queue empty
        p4IsConsuming = 0;
        sm_f1_ptr->num = 0;
      }
    }  
    sem_post((sem_t *) &sm_f1_ptr->mutex);
  }
  close(pipeEntrance);
}

void p4Handler() {
  p4IsConsuming = 1;
}

// p4Handler need's to access global vars, signal can't pass args
// https://cboard.cprogramming.com/linux-programming/147409-pass-user-parameter-signal-handler-linux.html
void p4(Shared_area_f1 sm_f1_ptr, int pipeEntrance1, int pipeEntrance2) {
  sem_wait((sem_t *) &sm_f1_ptr->mutex);
  // put p4 pid on shared mem to p123 signaling
  sm_f1_ptr->consumer_pid = getpid();
  sem_post((sem_t *) &sm_f1_ptr->mutex);
  signal(SIGUSR1, p4Handler);
  pthread_t tid;
  struct args args_t1 = {sm_f1_ptr, pipeEntrance1};
  struct args args_t2 = {sm_f1_ptr, pipeEntrance2};
  pthread_create(&tid, NULL, p4Consumer, (void*) &args_t2); // t2 sends to p6
  p4Consumer((void*) &args_t1); // t1(root thread) sends to p5
}

void p56(Shared_area_f2 sm_f2_ptr, int pipeExit) {
  int i, value, res;
  while(1) {
    // if pipe is readable, process it
    if (read(pipeExit, &value, sizeof(int)) >= 0) {	
      sem_wait((sem_t *) &sm_f2_ptr->mutex);
      if(!queue_full(&sm_f2_ptr->queue)) {
        // send to shared mem
        queue_push(&sm_f2_ptr->queue, value);
        sm_f2_ptr->p56qnt++; //sum one value processed
      }
      sem_post((sem_t *) &sm_f2_ptr->mutex);
    }	
  }
  close(pipeExit);
}

void p7ShowStats() {
  int i = 0, indexMode, indexMin, indexMax;
  int qntReps;
  for(i = 0; !reps[i]; i++); // goto first observed num
  indexMin = i;
  indexMax = i;
  indexMode = i;
  qntReps = reps[i];
  while(i < MAX_RANGE) {
    if(reps[i] > qntReps) {
      qntReps = reps[i];
      indexMode = i;
    }
    if(reps[i]) indexMax = i;
    i++;
  }
  printf("Moda: %d | Valor minimo: %d | Valor maximo: %d", indexMode + 1, indexMin + 1, indexMax + 1);
}

void* p7Threads(void* arg) {
  int i, signal, value;
  Shared_area_f2 sm_f2_ptr = (Shared_area_f2) arg;
  while(1) {
    sem_wait((sem_t *) &sm_f2_ptr->mutex);
    if(!queue_empty(&sm_f2_ptr->queue)) {
      // counting impressions
      if(counter < 10000) {
        counter++;
      } else {
        sem_post((sem_t *) &sm_f2_ptr->mutex);
        break;
      }
      queue_pop(&sm_f2_ptr->queue, &value);
      printf("%d\n", value);
      reps[value - 1]++;
    }  
    sem_post((sem_t *) &sm_f2_ptr->mutex);
  }
}

void p7(Shared_area_f2 sm_f2_ptr) {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, p7Threads, (void*) sm_f2_ptr);
  pthread_create(&tid2, NULL, p7Threads, (void*) sm_f2_ptr);
  p7Threads(sm_f2_ptr);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  p7ShowStats();
}
