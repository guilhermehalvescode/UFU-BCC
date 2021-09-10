#include "procs.h"
#define F1_KEY 1245
#define F2_KEY 6548


int main()
{
  pid_t p;
  int id = 0, pipe1[2], pipe2[2];
	Shared_area_f1 sm_f1_ptr;
	Shared_area_f2 sm_f2_ptr;
  int canal[2];
  
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
    if ((p = fork()) < 0) {
      printf("fork error\n"); 
      exit(-1);
    }
    if (p == 0) break;	  
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
  } else  if (id == 8) {
    printf("Executa o codigo do Processo Pai\n");
/*  Ele pode aguardar os demais processos ou simplesmente finalizar neste ponto. 
    Lembre-se, o termino do Pai antes dos processos filhos nao causa o termino dos
    processos filhos. 
*/    
  }
 exit(0); /* Executado por todos os processos ao finalizarem */
}