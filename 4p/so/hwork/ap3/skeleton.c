#include <stdio.h>
#include <stdlib.h>
#include "procs.h"
#include <sys/shm.h>
#define F1_KEY 1245
#define F2_KEY 6548

/* Inclua aqui todos os demais headers necessaarios */

int main()
{
  pid_t p;
  int id = 0, pipe0[2], pipe1[2];
	Shared_area sm_f1_ptr;
	Shared_area sm_f2_ptr;
  int canal[2];
  
  //gen f1 queue on shared mem
  if((sm_f1_ptr = gen_shared_queue_area(F1_KEY)) == NULL) {
    printf("gen_shared_queue_area on f1 error!\n");
    exit(-1);
  }

  //init sem for f1 shared mem
  if (sem_init((sem_t *) &sm_f1_ptr->mutex, 1, 1)) {
    printf("sem_init error\n");
    exit(-1);
  }

  //init pipes
  if(pipe(pipe0) == -1) {
    printf("pipe0 error!\n");
    exit(-1);
  }
  if(pipe(pipe1) == -1) {
    printf("pipe1 error!\n");
    exit(-1);
  }

  //gen f2 queue on shared mem
  if((sm_f2_ptr = gen_shared_queue_area(F2_KEY)) == NULL) {
    printf("gen_shared_queue_area on f2 error!\n");
    exit(-1);
  }
/* 
  Crie todos os recursos compartilhados aqui: 
  Ex.: Shared Memories (Filas), Pipes e Semaforos.
  ...
  ...
*/
  for(id = 1; id <= 7; id++) {
    if ((p = fork()) < 0) {
      printf("fork error\n"); 
      exit(-1);
    }
    if (p == 0) break;	  
  }


  if (id <= 3) {
    p123(sm_f1_ptr, id);
  } else if (id == 4) {
    p4(sm_f1_ptr, pipe0, pipe1);
  } else if (id == 5) {
    printf("Executa o codigo de P5\n");
  } else if (id == 6) {
    printf("Executa o codigo de P6\n");
  } else if (id == 7) {
    printf("Executa o codigo de P7\n");
  } else  if (id == 8) {
    printf("Executa o codigo do Processo Pai\n");
/*  Ele pode aguardar os demais processos ou simplesmente finalizar neste ponto. 
    Lembre-se, o termino do Pai antes dos processos filhos nao causa o termino dos
    processos filhos. 
*/    
  }
 exit(0); /* Executado por todos os processos ao finalizarem */
}