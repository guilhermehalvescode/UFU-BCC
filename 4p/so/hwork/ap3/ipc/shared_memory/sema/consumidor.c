#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <semaphore.h>


#define MEM_SZ 4096
#define BUFF_SZ MEM_SZ-sizeof(sem_t)-sizeof(int)

struct shared_area{	
	sem_t mutex;
	int num;
	char buffer[BUFF_SZ];
}

main()
{
  	int i;
	key_t key=5678;
	struct shared_area *shared_area_ptr;
	void *shared_memory = (void *)0;
	int shmid;

	shmid = shmget(key,MEM_SZ,0666|IPC_CREAT);
	if ( shmid == -1 )
	{
		printf("shmget falhou\n");
		exit(-1);
	}
	
	printf("shmid=%d\n",shmid);
	
	shared_memory = shmat(shmid,(void*)0,0);
	
	if (shared_memory == (void *) -1 )
	{
		printf("shmat falhou\n");
		exit(-1);
	}
		
	printf("Memoria compartilhada no endereco=%p\n", shared_memory);

	shared_area_ptr = (struct shared_area *) shared_memory;
	
	if ( sem_init((sem_t*)&shared_area_ptr->mutex,1,1) != 0 )
	{
		printf("sem_init falhou\n");
		exit(-1);
	}
	
	for(;;)
	{
				
			sem_wait((sem_t*)&shared_area_ptr->mutex);
			     if ( shared_area_ptr->num > 0 )
			     {	
			         for(i=0;i<shared_area_ptr->num;i++)
			                printf("%c",shared_area_ptr->buffer[i]);
			         shared_area_ptr->num=0;
				 printf("\nConsumiu %d bytes\n",i); 
			      }	
			sem_post((sem_t*)&shared_area_ptr->mutex);
		
	}

        exit(0);
}


	
	
