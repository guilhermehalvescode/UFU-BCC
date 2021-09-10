#include "./libs/procs.h"
#include <sys/wait.h>

int main()
{
  clock_t startTime = clock();
  pid_t pids[7];
  int id = 0, pipe1[2], pipe2[2];
	Shared_area_f1 sm_f1_ptr;
	Shared_area_f2 sm_f2_ptr;
  int canal[2];
  srand(time(NULL)); // seed to diff numbers between tests
  //gen f1 queue on shared mem
  if((sm_f1_ptr = gen_shared_area(F1_KEY, 1)) == NULL) {
    printf("gen_shared_area on f1 error!\n");
    exit(-1);
  }

  //init sem for f1 shared mem
  if (sem_init((sem_t *) &sm_f1_ptr->mutex, 1, 1)) {
    printf("sem_init error\n");
    exit(-1);
  }

  //init pipes
  if(pipe(pipe1) == -1) {
    printf("pipe0 error!\n");
    exit(-1);
  }
  if(pipe(pipe2) == -1) {
    printf("pipe1 error!\n");
    exit(-1);
  }

  //gen f2 queue on shared mem
  if((sm_f2_ptr = gen_shared_area(F2_KEY, 0)) == NULL) {
    printf("gen_shared_area on f2 error!\n");
    exit(-1);
  }

  //init sem for f2 shared mem
  if (sem_init((sem_t *) &sm_f2_ptr->mutex, 1, 1)) {
    printf("sem_init error\n");
    exit(-1);
  }

  for(id = 1; id <= 7; id++) {
    if ((pids[id - 1] = fork()) < 0) {
      printf("fork error\n"); 
      exit(-1);
    }
    if (pids[id - 1] == 0) break;	  
  }

  if (id <= 3) {
    p123(sm_f1_ptr);
  } else if (id == 4) {
    // p4 only needs to write to pipes FD's
    p4(sm_f1_ptr, pipe1[1], pipe2[1]);
  } else if (id == 5) {
    // p56 only needs to read from pipes FD's
    p56(sm_f2_ptr, pipe1[0]);
  } else if (id == 6) {
    // p56 only needs to read from pipes FD's
    p56(sm_f2_ptr, pipe2[0]);
  } else if (id == 7) {
    p7(sm_f2_ptr);
    sem_wait((sem_t *) &sm_f2_ptr->mutex);
    printf(" | Valores processados por P6 e P7: %d", sm_f2_ptr->p56qnt);
    sem_post((sem_t *) &sm_f2_ptr->mutex);
    clock_t endTime = clock();
    printf(" | Tempo gasto: %f\n", (double) (endTime - startTime) / CLOCKS_PER_SEC);
  } else if (id == 8) {
    int i, j;
    for(i = 0; i < 7; i++) {
      wait(&id); // id is unused
      // if one proc ends, shut down every one
      if(i == 0) 
        for(j = 0; j < 7; j++) 
          kill(pids[j], SIGKILL);
    }
    // freeing all resources
    sem_destroy((sem_t *) &sm_f1_ptr->mutex);
    sem_destroy((sem_t *) &sm_f2_ptr->mutex);
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    shmdt(sm_f1_ptr);
    shmctl(F1_KEY, IPC_RMID, NULL);
    shmdt(sm_f2_ptr);
    shmctl(F2_KEY, IPC_RMID, NULL);
  }
 exit(0);
}